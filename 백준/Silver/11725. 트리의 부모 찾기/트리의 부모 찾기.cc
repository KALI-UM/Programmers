#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> tree;
vector<int> parent;
vector<bool> visited;

void DFS(int node)
{
	if (visited[node] == true)return;
	visited[node] = true;

	for (int i = 0; i < tree[node].size(); i++)
	{
		if (tree[node][i] != parent[node] && parent[tree[node][i]] == -1)
		{
			parent[tree[node][i]] = node;
			DFS(tree[node][i]);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	tree = vector<vector<int>>(N + 1, vector<int>());
	parent = vector<int>(N + 1, -1);

	int a, b;
	for (int i = 1; i < N; i++)
	{
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	parent[1] = 0;
	visited = vector<bool>(N + 1, false);
	for (int i = 1; i < N + 1; i++)
	{
		DFS(i);
	}

	for (int i = 2; i < N + 1; i++)
		cout << parent[i] << "\n";
}