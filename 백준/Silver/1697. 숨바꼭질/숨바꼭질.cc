#include <iostream>
#include <queue>
using namespace std;
int N, M;

int dist[200002];

void BFS()
{
	fill(&dist[0], &dist[2 * (N < M ? M : N)], -1);
	queue<int> q;
	q.push(N);
	dist[N] = 0;
	while (!q.empty())
	{
		int curr = q.front();
		q.pop();
		if (curr == M)break;
		for (int next : {curr + 1, curr - 1, curr * 2})
		{
			if (next < 0 || next > 2 * (N < M ? M : N) || dist[next] != -1)continue;
			dist[next] = dist[curr] + 1;
			q.push(next);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	BFS();
	cout << dist[M] << '\n';
}