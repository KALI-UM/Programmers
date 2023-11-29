#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;
//다익스트라
vector<vector<pair<int, int>>> list;
vector<int> dist;
void BFS(int s)
{
	vector<bool> visited(list.size(), false);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	dist[s] = 0;
	q.emplace(dist[s], s);
	while (!q.empty())
	{
		pair<int, int> nownode = q.top();
		q.pop();

		if (visited[nownode.second])continue;
		visited[nownode.second] = true;

		for (int i = 0; i < list[nownode.second].size(); i++)
		{
			int n = list[nownode.second][i].first;
			int d = list[nownode.second][i].second;

			if (dist[n] > dist[nownode.second] + d)
			{
				dist[n] = dist[nownode.second] + d;
				q.emplace(dist[n], n);
			}
		}
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, E, S;
	cin >> N >> E >> S;

	list.resize(N + 1);
	dist = vector<int>(N + 1, INT_MAX);
	dist[S] = 0;
	int a, b, d;
	for (int i = 0; i < E; i++)
	{
		cin >> a >> b >> d;
		list[a].push_back(make_pair(b, d));
	}

	BFS(S);

	for (int i = 1; i <= N; i++)
	{
		if (dist[i] != INT_MAX)
			cout << dist[i] << "\n";

		else
			cout << "INF" << "\n";
	}

}