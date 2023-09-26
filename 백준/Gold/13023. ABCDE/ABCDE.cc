#include <iostream>
#include <vector>

using namespace std;
bool friend5 = false;
void dfs(vector<vector<int>>& v, vector<bool>& visited, int index, int depth)
{
	if (depth >= 4)
	{
		friend5 = true; 
		return;
	}

	visited[index] = true;
	for (int i = 0; i < v[index].size(); i++)
	{
		if (visited[v[index][i]] == false)
			dfs(v, visited, v[index][i], depth+1);
	}
	visited[index] = false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, E;
	cin >> N >> E;
	
	vector<vector<int>>v(N, vector<int>());

	int n, m;
	for (int i = 0; i < E; i++)
	{
		cin >> n >> m;
		v[n].push_back(m);
		v[m].push_back(n);
	}

	for (int i = 0; i < N; i++)
	{
		vector<bool> visited(N, false);
		dfs(v, visited, i, 0);
		if (friend5 == true)break;
	}

	cout << (friend5 ? 1 : 0);
}