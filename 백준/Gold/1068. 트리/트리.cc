#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> tree;
vector<bool> visited;
vector<int> parent;
int result;
void DFS(int node)
{
	if (visited[node] == true)return;
	visited[node] = true;

	if (tree[node].size() == 0)result--;
	for (int i = 0; i < tree[node].size(); i++)
	{
		DFS(tree[node][i]);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	tree = vector<vector<int>>(N, vector<int>());
	parent = vector<int>(N);
	int a;
	for (int i = 0; i < N; i++)
	{
		cin >> a;
		parent[i] = a;
		if (a == -1)continue;

		tree[a].push_back(i);
	}
	int D;
	cin >> D;
	visited = vector<bool>(N + 1, false);
	DFS(D);
	for (int i = 0; i < N; i++)
	{
		if (tree[i].size() == 0)
			result++;
	}

	if (tree[parent[D]].size() == 1)result++;

	cout << result << "\n";
}