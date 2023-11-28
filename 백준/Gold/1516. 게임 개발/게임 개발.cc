#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> list;
vector<int> indegree;
vector<int> buildtime;
vector<int> result;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	list.resize(N + 1);
	indegree.resize(N + 1);
	buildtime.resize(N + 1);
	result.resize(N + 1);
	for (int i = 1; i <= N; i++)
	{
		int a;
		cin >> buildtime[i];
		cin >> a;
		while (a != -1)
		{
			list[a].push_back(i);
			indegree[i]++;
			cin >> a;
		}
	}

	queue<int> q;
	for (int i = 1; i <= N; i++)
		if (indegree[i] == 0)q.push(i);

	while (!q.empty())
	{
		int nownode = q.front();
		q.pop();

		for (int n : list[nownode])
		{
			indegree[n]--;
			result[n] = max(result[n], result[nownode] + buildtime[nownode]);

			if (indegree[n] == 0)q.push(n);
		}
	}

	for (int i = 1; i <= N; i++)
		cout << result[i]+buildtime[i] << "\n";
}