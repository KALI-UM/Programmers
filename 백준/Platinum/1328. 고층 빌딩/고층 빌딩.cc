#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, L, R;
	cin >> N >> L >> R;
	vector<vector<vector<long>>> DP(N + 1, vector<vector<long>>(L + 1, vector<long>(R + 1, 0)));
	DP[1][1][1] = 1;

	for (int n = 2; n <= N; n++)
	{
		for (int l = 1; l <= L; l++)
		{
			for (int r = 1; r <= R; r++)
			{
				DP[n][l][r] = (DP[n - 1][l - 1][r] + DP[n - 1][l][r - 1] + DP[n - 1][l][r] * (n - 2))%1000000007;
			}
		}
	}
	cout << DP[N][L][R]<<"\n";
}