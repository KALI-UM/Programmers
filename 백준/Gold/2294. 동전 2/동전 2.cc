#include <iostream>
#include <vector>
using namespace std;
int N, M;

vector<int> coin;
vector<int> DP(10010, -1);
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	coin.resize(N);
	for (int c = 0; c < N; c++)
		cin >> coin[c];
	DP[0] = 0;
	for (int c = 0; c < N; c++)
	{
		for (int i = coin[c]; i <= M; i++)
		{
			if (DP[i] == -1)
			{
				if (DP[i - coin[c]] == -1)continue;
				DP[i] = DP[i - coin[c]] + 1;
			}
			else
			{
				if (DP[i - coin[c]] == -1)continue;
				DP[i] =min(DP[i], DP[i - coin[c]] + 1);
			}
		}
	}
	cout << DP[M] << '\n';
}