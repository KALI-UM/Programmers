#include <iostream>
#include <algorithm>

using namespace std;
int V, E;
int Cost[401][401];
const int INF = 1e9;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> V >> E;

	fill(&Cost[0][0], &Cost[400][401], INF);
	int a, b, c;
	for (int e = 0; e < E; e++)
	{
		cin >> a >> b >> c;
		Cost[a][b] = c;
	}

	for (int i = 1; i <= V; i++)
		Cost[i][i] = 0;

	for (int k = 1; k <= V; k++)
	{
		for (int i = 1; i <= V; i++)
		{
			for (int j = 1; j <= V; j++)
			{
				if (i == j)continue;

				if (Cost[i][j] > Cost[i][k] +Cost[k][j])
					Cost[i][j] = Cost[i][k] +Cost[k][j];
			}
		}
	}

	int Min = INF;
	for (int i = 1; i <= V; i++)
	{
		for (int j = 1; j <= V; j++)
		{
			if (i != j && Min > Cost[i][j] + Cost[j][i])
				Min = Cost[i][j] + Cost[j][i];
		}
	}
	if (Min == INF)Min = -1;
	cout << Min << '\n';

}