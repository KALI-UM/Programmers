#include <iostream>
#include <algorithm>
using namespace std;

int N, T;
long long DP[2][21];
long long nCmMemo[21][21];

long long nCm(int n, int m)
{
	long long result = 1;
	if (nCmMemo[n][m] == -1)
	{
		long long nn = (long long)n;
		long long mm = (long long)m;
		while (nn > (long long)(n-m))
		{
			result *= nn;
			nn--;
		}
		while (mm > 1)
		{
			result /= mm;
			mm--;
		}
		nCmMemo[n][m] = result;
	}
	else
	{
		result = nCmMemo[n][m];
	}
	return result;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	fill(&nCmMemo[0][0], &nCmMemo[20][21], -1);
	for (int i = 0; i <= 20; i++)
	{
		nCmMemo[i][0] = 1;
		nCmMemo[i][i] = 1;
	}

	cin >> T;

	DP[0][0] = 1;
	DP[1][0] = 1;
	DP[0][1] = 1;
	DP[1][1] = 1;

	int t = T;
	while (t > 0)
	{
		cin >> N;

		if (N != 1)
		{
			for (int i = 2; i <= N; i++)
			{
				if (DP[0][i] == 0 || DP[1][i] == 0)
					for (int j = 0; j <= i - 1; j++)
					{
						DP[j % 2][i] += DP[j % 2][j] * DP[1][i - j - 1] * nCm(i - 1, j);
					}
			}
			cout << DP[0][N] + DP[1][N] << "\n";
		}
		else
			cout << 1 << "\n";
		t--;
	}
}
