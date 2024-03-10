#include <iostream>
#include <algorithm>

using namespace std;
#define INF 1e9
int T;
int C;

int DP[501][501];
int sum[501];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> C;
		fill(&DP[0][0], &DP[0][500], 0);
		for (int c = 1; c <= C; c++)
		{
			cin >> DP[0][c];
			sum[c] = sum[c - 1] + DP[0][c];
		}

		for (int k = 1; k - 1 <= C; k++)
		{
			int i = 1;
			int j = k + 1;

			for (int u = 0; u < C - k; u++)
			{
				DP[i][j] = INF;
				for (int m = i; m <= j; m++)
					DP[i][j] = min(DP[i][j], DP[i][m] + DP[m + 1][j] + sum[j] - sum[i - 1]);

				i++;
				j++;
			}
		}
		cout << DP[1][C] << "\n";
	}
}