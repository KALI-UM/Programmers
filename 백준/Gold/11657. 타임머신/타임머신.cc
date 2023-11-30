#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
//벨만포드

#define C1 0
#define C2 1
#define W 2

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, E;
	cin >> N >> E;

	vector<vector<int>> EdgeInfo(E);
	vector<long> distance(N + 1, LONG_MAX);
	distance[1] = 0;
	int c1, c2, w;
	for (int i = 0; i < E; i++)
	{
		cin >> c1 >> c2 >> w;
		EdgeInfo[i].push_back(c1);
		EdgeInfo[i].push_back(c2);
		EdgeInfo[i].push_back(w);
	}

	for (int i = 0; i < N - 1; i++) //노드갯수-1만큼 반복
		for (vector<int>& edge : EdgeInfo)
		{
			long temp = distance[edge[C1]] + edge[W];
			if (distance[edge[C1]] != LONG_MAX && distance[edge[C2]] > temp)
				distance[edge[C2]] = temp;
		}

	bool isNegativeCycle = false;
	for (vector<int>& edge : EdgeInfo)
	{
		long temp = distance[edge[C1]] + edge[W];
		if (distance[edge[C1]] != LONG_MAX && distance[edge[C2]] > temp)
			isNegativeCycle = true;
	}

	if (isNegativeCycle)cout << -1 << "\n";
	else
	{
		for (int i = 2; i <= N; i++)
		{
			if (distance[i] != LONG_MAX)
				cout << distance[i] << "\n";
			else
				cout << -1 << "\n";
		}
	}
}