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
	for (int i = 1; i <= N; i++)
		EdgeInfo[i][i] = 0;

	int a, b, c;
	for (int i = 0; i < E; i++)
	{
		cin >> a >> b >> c;
		if (c < EdgeInfo[a][b])
			EdgeInfo[a][b] = c;
	}

	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (EdgeInfo[i][j] > EdgeInfo[i][k] + EdgeInfo[k][j])
					EdgeInfo[i][j] = EdgeInfo[i][k] + EdgeInfo[k][j];
			}
		}

	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			if (EdgeInfo[k][i] == 10000001) cout << 0 << ' ';
			else cout << EdgeInfo[k][i] << ' ';
		}
		cout << "\n";
	}

}