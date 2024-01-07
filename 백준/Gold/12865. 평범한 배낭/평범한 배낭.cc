#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include <cmath>
using namespace std;

int N, K;
struct item
{
	int weight;
	int worth;
};

vector<vector<int>> DP;
vector<item> list;

bool comp_worth(item& a, item& b)
{
	return a.worth > b.worth ? true : a.worth == b.worth ? a.weight < b.weight : false;
}

bool comp_weight(item& a, item& b)
{
	return a.weight > b.weight ? true : a.weight == b.weight ? a.worth < b.worth : false;
}

void AddDP(int node, int k)
{
	for (int i = 0; i < N; i++)
	{
		if (i == 0)
		{
			if (list[i].weight <= k)
				DP[k][i] = list[i].worth;

		}
		else
		{
				DP[k][i] = max(DP[k][i - 1], DP[k - 1][i - 1] + list[i].worth);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> K;
	DP = vector<vector<int>>(K+1, vector<int>(N, 0));
	list = vector<item>(N);
	sort(list.begin(), list.end(), comp_worth);

	for (int i = 0; i < N; i++)
		cin >> list[i].weight >> list[i].worth;

	for (int k = 1; k <= K; k++)
	{
		for (int i = 0; i < N; i++)
		{
			if (i == 0)
			{
				if (list[i].weight <= k)
					DP[k][i] = list[i].worth;
			}
			else
			{
				if (list[i].weight <= k)
					DP[k][i] = max(DP[k][i - 1], DP[k - list[i].weight][i - 1] + list[i].worth);

				else
					DP[k][i] = DP[k][i - 1];

			}
		}
	}
	cout << DP[K][N-1] << "\n";
}