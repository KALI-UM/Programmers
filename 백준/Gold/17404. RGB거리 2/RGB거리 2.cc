#include <iostream>
#include <algorithm>
using namespace std;

int N;
int Cost[1001][3];
int DP[3][1001][3];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	fill(&DP[0][0][0], &DP[2][2][1000], 1e9);
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> Cost[i][0] >> Cost[i][1] >> Cost[i][2];

	int Result = 1e9;
	for (int RGB = 0; RGB < 3; RGB++)
	{
		DP[RGB][1][RGB] = Cost[1][RGB];
		for (int i = 1; i < N; i++)
		{
			for (int rgb = 0; rgb < 3; rgb++)
				DP[RGB][i + 1][rgb] = min(DP[RGB][i][(rgb + 1) % 3] + Cost[i + 1][rgb], DP[RGB][i][(rgb + 2) % 3] + Cost[i + 1][rgb]);
		}
		DP[RGB][N][RGB] = min(DP[RGB][N][(RGB + 1) % 3], DP[RGB][N][(RGB + 2) % 3]);
		if (DP[RGB][N][RGB] < Result)Result = DP[RGB][N][RGB];
	}
	cout << Result << '\n';
}