#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, K;
vector<int> Coin;
vector<int> DP;
int answer = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	DP.resize(K + 1);
	int temp;
	for (int i = 1; i <= N; i++)
	{
		cin >> temp;
		if (temp > K)
			continue;
		Coin.push_back(temp);
		DP[0] = 1;
	}

	sort(Coin.begin(), Coin.end());

	for (int j = 0; j < Coin.size(); j++)
	{
		for (int i = Coin[j]; i <= K; i++)
		{
			DP[i] += DP[i - Coin[j]];
		}
	}
	cout << DP[K];
}