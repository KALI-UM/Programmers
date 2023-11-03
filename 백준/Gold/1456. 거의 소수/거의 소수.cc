#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long N, M;
	cin >> N >> M;

	int result = 0;
	vector<bool> numbers(sqrt(M) + 2, true);
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

	for (int i = 2; i < numbers.size(); i++)
	{
		if (numbers[i] == true)
		{
			for (int j = 2;; j++)
			{
				double temp = pow(i, j);
				if (temp >= N)
				{
					if (temp > M)
						break;
					result++;
				}
			}
		}
	}

	cout << result << "\n";
}