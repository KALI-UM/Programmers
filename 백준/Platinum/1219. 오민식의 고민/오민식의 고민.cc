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

	int N, Start, End, E;
	cin >> N >> Start >> End >> E;

	vector<vector<int>> EdgeInfo(E);
	vector<long> distance(N, LONG_MIN);
	vector<int> citymoney(N);
	int c1, c2, w;
	for (int i = 0; i < E; i++)
	{
		cin >> c1 >> c2 >> w;
		EdgeInfo[i].push_back(c1);
		EdgeInfo[i].push_back(c2);
		EdgeInfo[i].push_back(w);
	}

	for (int i = 0; i < N; i++)
		cin >> citymoney[i];

	distance[Start] = citymoney[Start];

	for (int i = 0; i < N+50; i++) //충분히 반복
		for (vector<int>& edge : EdgeInfo)
		{
			if (distance[edge[C1]] == LONG_MAX)
				distance[edge[C2]] = LONG_MAX;

			else
			{
				long temp = distance[edge[C1]] - (long)edge[W] + (long)citymoney[edge[C2]];
				if (distance[edge[C1]] != LONG_MIN && distance[edge[C2]] < temp)
				{
					if (i >= N - 1)temp = LONG_MAX;
					distance[edge[C2]] = temp;
				}
			}
		}

	if (distance[End] == LONG_MIN)
		cout << "gg" << "\n";
	else if (distance[End] == LONG_MAX)
		cout << "Gee" << "\n";
	else
		cout << distance[End] << "\n";
}