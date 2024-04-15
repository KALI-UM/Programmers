#include <iostream>

using namespace std;
int N, K;
int Result = 0;
int Mod = 1000000003;
int DP[1001][501] = { 0, };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> K;

	if (K <= (N / 2))
	{
		for (int i = 0; i <= N; i++)
		{
			DP[i][0] = 1;
			DP[i][1] = i;
		}
		for (int i = 2; i <= N; i++)
		{
			for (int k = 2; k <= K; k++)
				DP[i][k] = (DP[i - 1][k] + DP[i - 2][k - 1]) % Mod;
		}
		Result = (DP[N - 1][K] + DP[N - 3][K - 1]) % Mod;
	}
    cout << Result << '\n';
}