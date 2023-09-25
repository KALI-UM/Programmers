#include <iostream>
#include <queue>
#include <vector>

using namespace std;
void done(vector<bool>& check, int& index)
{
	for (int i = index; i < check.size(); i++)
	{
		if (check[i] == false)
		{
			check[i] = true;
			index = i;
			return;
		}
	}
	index = 0;
}

void dfs(vector<vector<int>>& v, vector<bool>& check, int index)
{
	for (int i = 0; i < v[index].size(); i++)
	{
		if (check[v[index][i]] == false)
		{
			check[v[index][i]] = true;
			dfs(v, check, v[index][i]);
		}
	}
}

int DFS(vector<vector<int>>& v)
{
	vector<bool>check(v.size(), false);
	int cnt = 0;

	int index = 1;
	check[index] = true;
	while (index != 0)
	{
		cnt++;
		dfs(v, check, index);
		done(check, index);
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

	//vector<pair<int, int>>v(E,make_pair(0,0));
	int n, m;
	vector<vector<int>>v(N + 1, vector<int>());
	for (int i = 0; i < E; i++)
	{
		cin >> n >> m;
		v[n].push_back(m);
		v[m].push_back(n);
	}

	cout<<DFS(v);
}