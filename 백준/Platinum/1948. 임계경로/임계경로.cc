#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> list;
vector<vector<int>> list_reverse;
vector<int> dist;
vector<int> in_degree;
int N, E;

void BFS(int s)
{
	queue<int> q;
	q.push(s);

	while (!q.empty())
	{
		int nownode = q.front();
		q.pop();

		for (int i = 0; i < list[nownode].size() / 2; i++)
		{
			in_degree[list[nownode][i * 2]]--;
			dist[list[nownode][i * 2]] = max(dist[nownode] + list[nownode][i * 2 + 1], dist[list[nownode][i * 2]]);
			
			if (in_degree[list[nownode][i * 2]] == 0)
				q.push(list[nownode][i * 2]);
		}
	}
}

int BFS_reverse(int e)
{
	vector<bool> visited(N + 1, false);
	queue<int> q;
	visited[e] = true;
	q.push(e);

	int result = 0;

	while (!q.empty())
	{
		int nownode = q.front();
		q.pop();

		for (int i = 0; i < list_reverse[nownode].size() / 2; i++)
		{
			int n = list_reverse[nownode][i * 2];

			if (dist[nownode] == dist[n] + list_reverse[nownode][i * 2 + 1])
			{
				result++;

				if (visited[n] == false)
				{
					visited[n] = true;
					q.push(n);
				}
			}
		}
	}

	return result;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> E;

	list = vector<vector<int>>(N + 1);
	list_reverse = vector<vector<int>>(N + 1);
	dist = vector<int>(N + 1, 0);
	in_degree = vector<int>(N + 1, 0);

	int a, b, d;
	for (int i = 0; i < E; i++)
	{
		cin >> a >> b >> d;
		list[a].push_back(b);
		list[a].push_back(d);

		list_reverse[b].push_back(a);
		list_reverse[b].push_back(d);

		in_degree[b]++;
	}

	int S, End;
	cin >> S >> End;

	BFS(S);

	cout << dist[End] << "\n" << BFS_reverse(End) << "\n";

}