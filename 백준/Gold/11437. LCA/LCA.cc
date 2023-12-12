#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>>tree;
vector<int> parent;
vector<int> depth;

void DFS(int d, int node)
{
	depth[node] = d;
	if (parent[node] != -1)
	{
		for (int n : tree[node])
		{
			if (n == parent[node])continue;

			parent[n] = node;
			DFS(d + 1, n);
		}
	}
	else if (tree[node].size() == 1 && node != 1)
	{
		parent[node] = tree[node][0];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int N, M;
	cin >> N;

	tree.resize(N + 1);
	parent = vector<int>(N + 1, -1);
	depth = vector<int>(N + 1, -1);

	int a, b;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	parent[1] = 0;
	DFS(0, 1);

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		int da = depth[a], db = depth[b];
		while (da != db)
		{
			if (da > db)
				a = parent[a];
			else
				b = parent[b];
			da = depth[a];
			db = depth[b];
		}
		while (a != b)
		{
			a = parent[a];
			b = parent[b];
		}
		cout << a << "\n";
	}
}