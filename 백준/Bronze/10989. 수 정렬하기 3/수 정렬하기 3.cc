#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int index = 0;
	vector<int> v(10001,0);
	for (int i = 0; i < N; i++)
	{
		cin >> index;
		 v[index]++;
	}


	for (int i = 1; i <= 10000; i++)
	{
		if (v[i] != 0)
		{
			if (v[i] == 1)
				cout << i << "\n";
			else
			{
				for (int j = 0; j < v[i]; j++)
					cout << i << "\n";
			}

		}
	}
}