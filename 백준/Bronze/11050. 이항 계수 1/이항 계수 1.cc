#include <iostream>
#include <vector>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int N, K;
	cin >> N >> K;

	vector<vector<int>> table(N + 1, vector<int>(N + 1, 0));

	for (int i = 0; i < N + 1; i++)
	{
		table[i][1] = i;
		table[i][0] = 1;
		table[i][i] = 1;
	}

	for (int n = 1; n <= N; n++)
	{
		for (int k = 2; k <= n; k++)
		{
			table[n][k] = table[n - 1][k] + table[n - 1][k - 1];
		}
	}
	cout << table[N][K]<<"\n";
}