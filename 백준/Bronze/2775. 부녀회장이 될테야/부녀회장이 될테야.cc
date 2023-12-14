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
	vector<vector<int>> table(1, vector<int>(15, 0));
	for (int i = 1; i < 15; i++)
		table[0][i] = i;

	int f, h;
	for (int t = 0; t < T; t++)
	{
		cin >> f >> h;
		if (table.size() <= f)
		{
			int ts = table.size();
			for (int i = ts; i <= f; i++)
			{
				table.push_back(vector<int>(15, 0));
				table[i][1] = 1;
				for (int j = 2; j <15; j++)
				{
					table[i][j] = table[i][j - 1] + table[i - 1][j];
				}
			}
		}

		cout << table[f][h] << "\n";
	}
}