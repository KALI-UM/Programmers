#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
static vector<vector<pair<int, int>>> v;
static vector<int> dist;
void BFS(int start)
{
	queue<int> q;
	vector<bool> visited(v.size(), false);
	visited[start] = true;
	q.push(start);
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		
		for (int i = 0; i < v[now].size(); i++)
		{
			if (visited[v[now][i].first] == false)
			{
				visited[v[now][i].first] = true;
				q.push(v[now][i].first);
				dist[v[now][i].first] = dist[now] + v[now][i].second;
			}
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
	v = vector<vector<pair<int, int>>>(N+1, vector<pair<int,int>>());
	dist = vector<int>(N+1, 0);
	int T, linkedNode,length;
	for (int i = 1; i <= N; i++)
	{
		cin >> T >> linkedNode;
		while (linkedNode != -1)
		{
			cin >> length;
			v[T].push_back(make_pair(linkedNode, length));
			cin >> linkedNode;
		}
	}

	BFS(1);

	int max = 1;
	for (int i = 2; i <= N; i++)
		dist[max] < dist[i] ? max = i : max;

	fill(dist.begin(), dist.end(), 0);
	BFS(max);

	int result= *max_element(dist.begin(), dist.end());
	cout << result <<"\n";
}