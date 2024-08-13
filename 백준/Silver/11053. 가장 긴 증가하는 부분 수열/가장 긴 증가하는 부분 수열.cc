#include <iostream>

using namespace std;

int N;
int Numbers[1001];
int DP[1002] = { 0, };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	int Max = -1;

	for (int i = 1; i <= N; i++)
	{
		cin >> Numbers[i];
		if (Numbers[i] > Max)Max = Numbers[i];
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = Numbers[i]; j <= Max; j++)
		{
			if (DP[j] >= DP[Numbers[i] - 1] + 1)break;

			DP[j] = DP[Numbers[i] - 1] + 1;
		}
	}

	cout << DP[Max] << "\n";
}

