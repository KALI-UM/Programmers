#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, E;
	cin >> N >> E;

	vector<vector<long>> EdgeInfo(N + 1, vector<long>(N + 1, 10000001));

	int a, b;
	for (int i = 0; i < E; i++)
	{
		{
			cin >> a >> b;
			EdgeInfo[a][b] = 1;
			EdgeInfo[b][a] = 1;
		}
	}

	for (int i = 1; i <= N; i++)
		EdgeInfo[i][i] = 0;

	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (EdgeInfo[i][j] >EdgeInfo[i][k] +EdgeInfo[k][j])
				{
					EdgeInfo[i][j] = EdgeInfo[i][k] + EdgeInfo[k][j];
				}
			}
		}

	int min = 1;
	for (int k = 1; k <= N; k++)
	{
		long temp = 0;
		for (int i = 1; i <= N; i++)
		{
			temp += EdgeInfo[k][i];
		}
		EdgeInfo[0][k] = temp;
		if (EdgeInfo[0][min] > EdgeInfo[0][k])
			min = k;
	}
	cout << min << "\n";

}