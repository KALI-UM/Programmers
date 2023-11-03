#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<bool> numbers(10000001, true);
	numbers[1] = false;
	for (int i = 2; i < numbers.size(); i++)
	{
		if (numbers[i] == true)
		{
			int max = (int)ceil((double)numbers.size() / (double)i);
			for (int j = 2; j < max; j++)
				numbers[i * j] = false;
		}
	}

	for (int i = N; i < numbers.size(); i++)
	{
		if (numbers[i] == true)
		{
			string target = to_string(i);
			bool panlindrome = true;
			for (int j = 0; j < target.length() / 2; j++)
			{
				if (target[j] != target[target.length() - j - 1])
				{
					panlindrome = false;
					break;
				}
			}

			if (panlindrome)
			{
				cout << i << "\n";
				break;
			}
		}
	}
}