#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int T, N, M;
int coin[20];
int DP[10001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		cin >> N;
		vector<int> coin(N);
		for (int n = 0; n < N; n++)
			cin >> coin[n];
		cin >> M;
		fill(&DP[0], &DP[10001], 0);
		for (int c = 0; c < N; c++)
		{	DP[coin[c]]++;
			for (int m = coin[c]; m <= M; m++)
			{
				DP[m]+=DP[m - coin[c]];
			}
		}
		cout << DP[M] << '\n';
	}
}

