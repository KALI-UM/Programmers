#include <iostream>
#include <algorithm>
using namespace std;

int N, M;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	int D, P;
	int DP[201] = { 0, };
	for (int i = 0; i < M; i++)
	{
		cin >> D >> P;

		for (int j = N; j>=D; j--)
		{
			DP[j] = max(DP[j], DP[j - D] + P);
		}
	}
	cout << DP[N]<<'\n';
}