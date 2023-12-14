#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int T;
	cin >> T;
	vector<vector<int>> table(1, vector<int>(31, 0));

	int N, M;
	for (int t = 0; t < T; t++)
	{
		cin >> N >> M;
		if (table.size() <= M)
		{
			int ts = table.size();
			for (int i = ts; i <= M; i++)
			{
				table.push_back(vector<int>(31, 0));
				table[i][1] = i;
				table[i][0] = 1;
				for (int j = 2; j < i; j++)
				{
					table[i][j] = table[i - 1][j - 1] + table[i - 1][j];
				}
				table[i][i] = 1;
			}
		}

		cout << table[M][N] << "\n";
	}
}