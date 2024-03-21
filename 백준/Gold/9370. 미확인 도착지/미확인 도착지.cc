#include <iostream>
#include <algorithm>
#include <string>
#include <limits.h>
#include <queue>

using namespace std;

int Q, N, E, D, S, E1, E2;
priority_queue<int, vector<int>, greater<int>> Destination;
int Cost[2001][2001];
int Way[3][2001];

void Dijkstra(int index, int s)
{
	priority_queue<pair<int, int>> pq;

	pq.push({ 0,s });
	Way[index][s] = 0;
	while (!pq.empty())
	{
		int node = pq.top().second;
		pq.pop();

		for (int n = 1; n <= N; n++)
		{
			if (Cost[node][n] != INT_MAX && Way[index][n] > Way[index][node] + Cost[node][n])
			{
				Way[index][n] = Way[index][node] + Cost[node][n];
				pq.push({ Cost[node][n], n });
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> Q;
	for (int q = 0; q < Q; q++)
	{
		cin >> N >> E >> D;
		cin >> S >> E1 >> E2;

		fill(&Cost[0][0], &Cost[2000][2001], INT_MAX);
		fill(&Way[0][0], &Way[2][2001], INT_MAX);
		for (int e = 0; e < E; e++)
		{
			int a, b, c;
			cin >> a >> b >> c;

			Cost[a][b] = c; Cost[b][a] = c;
		}

		for (int d = 0; d < D; d++)
		{
			int temp;
			cin >> temp;
			Destination.push(temp);
		}

		Dijkstra(0, S);
		Dijkstra(1, E1);
		Dijkstra(2, E2);

		while (!Destination.empty())
		{
			int d = Destination.top();
			Destination.pop();

			if (Way[0][d] != INT_MAX && (Way[0][d] == Way[0][E1] + Way[2][d] + Cost[E1][E2] || Way[0][d] == Way[0][E2] + Way[1][d] + Cost[E1][E2]))
				cout << d << ' ';
		}
		cout << "\n";
	}
}
