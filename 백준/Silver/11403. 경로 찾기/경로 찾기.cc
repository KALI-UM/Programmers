#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<vector<bool>> EdgeInfo(N, vector<bool>(N));

	int w;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> w;
			if (w == 0)EdgeInfo[i][j] = false;
			else EdgeInfo[i][j] = true;
		}
	}

	for (int k = 0; k < N; k++)
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (EdgeInfo[i][k] && EdgeInfo[k][j])
					EdgeInfo[i][j] = true;
			}
		}

	for (int k = 0; k < N; k++)
	{
		for (int i = 0; i < N; i++)
		{
			cout << EdgeInfo[k][i] << ' ';
		}
		cout << "\n";
	}

}