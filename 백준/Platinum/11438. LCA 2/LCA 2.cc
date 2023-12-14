#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

vector<vector<int>> tree;
vector<vector<int>> parent;
vector<int> depth;
int maxdepth = 0;

void BFS(int node)
{
	queue<int> q;
	q.push(node);
	depth[node] = 0;

	while (!q.empty())
	{
		int n = q.front();
		q.pop();

		for (int& child : tree[n])
		{
			if (depth[child] != -1)continue;

			depth[child] = depth[n] + 1;
			parent[0][child] = n;
			q.push(child);
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
	tree.resize(N + 1);
	parent.push_back(vector<int>(N + 1, 0));
	depth = vector<int>(N + 1, -1);
	int a, b;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	BFS(1);

	int temp = 1;
	while (temp <= N)
	{
		temp <<= 1;
		maxdepth++;
	}

	for (int i = 1; i <= maxdepth; i++)
	{
		parent.push_back(vector<int>(N + 1, 0));
		for (int j = 1; j <= N; j++)
		{
			parent[i][j] = parent[i - 1][parent[i - 1][j]];
		}
	}

	int M;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		if (depth[a] > depth[b])swap(a, b);
		for (int k = maxdepth; k >= 0; k--)
		{
			if ((pow(2, k) <= depth[b] - depth[a]) &&(depth[a]<=depth[parent[k][b]]))
			{
				b = parent[k][b];
			}
		}
		for (int k = maxdepth; k >= 0 && a != b; k--)
		{
			if (parent[k][a] != parent[k][b])
			{
				a = parent[k][a];
				b= parent[k][b];
			}
		}

		if (a != b)
			a = parent[0][a];
		cout << a << "\n";
	}

}