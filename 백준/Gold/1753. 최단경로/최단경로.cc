#include <iostream>

#include <queue>
#include <vector>
#include <climits>

using namespace std;
int V, E;
int Start;
vector<int> result;
vector<bool> visited;
vector<vector<pair<int, int>>> list;
priority_queue < pair<int, int >> Edges;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V >> E >> Start;

	result = vector<int>(V + 1, INT_MAX);
	result[Start] = 0;
	visited = vector<bool>(V + 1, false);
	list = vector<vector<pair<int, int>>>(V + 1);

	int u, v, w;
	for (int i = 0; i < E; i++)
	{
		cin >> u >> v >> w;
		list[u].push_back({ v,w });
	}

	Edges.push({ 0,Start });
	while (!Edges.empty())
	{
		int curr = Edges.top().second;

		Edges.pop();

		if (visited[curr])continue;
		visited[curr] = true;

		for (int i = 0; i < list[curr].size(); i++)
		{
			int next = list[curr][i].first;
			int curr2next = list[curr][i].second;
			if (result[next] >= INT_MAX || result[next] > result[curr] + curr2next)
			{
				result[next] = result[curr] + curr2next;
				Edges.push({ -result[next], next });
			}
		}
	}

	for (int i = 1; i <= V; i++)
	{
		if (visited[i])
			cout << result[i] << '\n';
		else
			cout << "INF" << '\n';
	}
}

