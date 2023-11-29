#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

vector<vector<pair<int,int>>> list;
vector<int> dist;

void BFS(int node)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.emplace(0, node);
	dist[node] = 0;

	vector<bool> visited(list.size(), false);

	while (!q.empty())
	{
		pair<int, int> nownode = q.top();
		q.pop();

		if (visited[nownode.second])continue;
		visited[nownode.second] = true;

		for (pair<int, int>& n : list[nownode.second])
		{
			if (dist[n.first] > dist[nownode.second] + n.second)
			{
				dist[n.first]=dist[nownode.second] + n.second;
				q.emplace(dist[n.first], n.first);
			}
		}
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, E;
	cin >> N >> E ;

	list.resize(N + 1);
	dist = vector<int>(N + 1, INT_MAX);

	int a, b, d;
	for (int i = 0; i < E; i++)
	{
		cin >> a >> b >> d;
		list[a].push_back(make_pair(b, d));
	}

	int Start, End;
	cin >> Start >> End;

	BFS(Start);
	cout << dist[End];
}