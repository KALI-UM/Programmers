#include <iostream>
using namespace std;
int N;
int K;

int DP[210][210];
int mod = 1000000000;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> K;

	DP[0][0] = 1;
	DP[1][1] = 1;
	for (int i = 2; i <= 200; i++)
	{
		DP[1][i] = 1;
		DP[i][1] = i;
	}

	for (int n = 2; n <= N; n++)
	{
		for (int i = 2; i <= K; i++)
			DP[i][n] += (DP[i][n - 1] + DP[i - 1][n]) % mod;
	}
	cout << DP[K][N] << '\n';
}