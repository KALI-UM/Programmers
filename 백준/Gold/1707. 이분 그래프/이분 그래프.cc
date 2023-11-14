#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> testcase;
vector<int> visited;

void DFS(int node)
{
	if (visited[0] == 0)return;

	for (int i : testcase[node])
	{
		if (visited[i] == -1)
		{
			visited[i] = (visited[node] + 1) % 2;
			DFS(i);
		}
		else if (visited[node] == visited[i])
			visited[0] = 0;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	int N, E;
	for (int i = 0; i < T; i++)
	{
		cin >> N >> E;
		testcase.clear();
		testcase.resize(N + 1);
		int a, b;
		for (int e = 0; e < E; e++)
		{
			cin >> a >> b;
			testcase[a].push_back(b);
			testcase[b].push_back(a);
		}

		visited.clear();
		visited.resize(N + 1, -1);
		visited[1] = 0;

		for (int j = 1; j <= N; j++)
		{
			if (visited[0] != 0)
				DFS(j);
			else
				break;
		}
		visited[0] == 0 ? cout << "NO" << "\n" : cout << "YES" << "\n";
	}
}