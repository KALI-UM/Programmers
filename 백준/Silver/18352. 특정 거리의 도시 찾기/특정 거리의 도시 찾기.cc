#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>> v;
vector<int> visited;

void BFS(int node)
{
	queue<int> q;
	q.push(node);

	while (!q.empty())
	{
		int nownode = q.front();
		q.pop();
		for (int i = 0; i < v[nownode].size(); i++)
		{
			if (visited[v[nownode][i]] == 0 && node != v[nownode][i])
			{
				q.push(v[nownode][i]);
				visited[v[nownode][i]] = visited[nownode] + 1;
			}
		}
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int City, Edge, Distance, Depart;
	cin >> City >> Edge >> Distance >> Depart;

	v = vector<vector<int>>(City + 1, vector<int>());
	visited = vector<int>(City + 1, 0);
	int a, b;
	for (int i = 0; i < Edge; i++)
	{
		cin >> a >> b;
		v[a].push_back(b);
	}

	BFS(Depart);

	vector<int> result;
	for (int i = 1; i <= City; i++)
	{
		if (visited[i] == Distance)
			result.push_back(i);
	}

	if (result.empty()) cout << "-1";
	else
	{
		for (int i : result)
			cout << i << "\n";
	}
}