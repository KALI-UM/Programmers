#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long K;
	cin >> K;
	vector<vector<long>> table(K + 1, vector<long>(10, 0));

	for (int i = 1; i < 10; i++)
		table[1][i] = 1;

	for (int i = 2; i <= K; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j != 0)
				table[i][j] += table[i - 1][j - 1];
			if (j != 9)
				table[i][j] += table[i - 1][j + 1];

			table[i][j] = table[i][j] % 1000000000;
		}
	}

	long result=0;
	for (long& temp : table[K])
		result += temp;
	cout << result%1000000000 << "\n";
}