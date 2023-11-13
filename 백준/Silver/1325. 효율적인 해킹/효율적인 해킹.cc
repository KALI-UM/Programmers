#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<vector<int>> computer;
vector<bool> visited;

int BFS(int node)
{
	queue<int> q;
	q.push(node);
	int cnt = 0;

	while (!q.empty())
	{
		int nownode = q.front();
		q.pop();
		visited[nownode] = true;
		for (int& target : computer[nownode])
		{
			if (visited[target] == false)
			{
				q.push(target);
				visited[target] = true;
				cnt++;
			}
		}
	}

	return cnt;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, E;
	cin >> N >> E;

	/// <summary>
	/// 신뢰받는 컴퓨터를 이중벡터로 가지고 있는다
	/// </summary>
	/// <returns></returns>
	computer = vector<vector<int>>(N + 1, vector<int>());

	int a, b;
	for (int i = 0; i < E; i++)
	{
		cin >> a >> b;
		computer[b].push_back(a);
	}

	int max = 0;
	vector<int> result(N + 1);
	visited = vector<bool>(N + 1, false);
	for (int i = 1; i <= N; i++)
	{
		result[i] = BFS(i);
		if (max < result[i])max = result[i];
		fill(visited.begin(), visited.end(), false);
	}

	for (int i = 1; i <= N; i++)
		if (result[i] == max)cout << i << ' ';
}