#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

vector<vector<int>> list;
vector<priority_queue<int>> dist;
int N, E, K;

void BFS(int node)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.emplace(0, node);
	dist[node].push(0);

	vector<bool> visited(list.size(), false);

	while (!q.empty())
	{
		pair<int, int> nownode = q.top();
		q.pop();

		for (int i=1; i<=N; i++)
		{
			if (list[nownode.second][i] == 0) continue;

			int temp = nownode.first + list[nownode.second][i];
			if (dist[i].empty()|| dist[i].size() < K)
			{
				dist[i].push(temp);
				q.emplace(temp, i);
			}
			else if (dist[i].size() >= K && dist[i].top() > temp)
			{
				dist[i].pop();
				dist[i].push(temp);
				q.emplace(temp, i);
			}

		}
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> E >> K;

	list= vector<vector<int>>(N + 1, vector<int>(N+1,0));
	dist.resize(N + 1);
	int a, b, d;
	for (int i = 0; i < E; i++)
	{
		cin >> a >> b >> d;
		list[a][b] = d;
	}

	BFS(1);

	for (int i = 1; i <= N; i++)
	{
		if (dist[i].size() < K)cout << "-1" << "\n";
		else
			cout << dist[i].top() << "\n";
	}
}