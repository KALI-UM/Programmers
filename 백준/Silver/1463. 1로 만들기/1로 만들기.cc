#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int K;
	cin >> K;

	vector<int> table(K + 1, 0);
	for (int i = 2; i < table.size(); i++)
	{
		table[i] = table[i - 1] +1;

		if (i % 2 == 0)table[i] = min(table[i], table[i / 2] + 1);
		if (i % 3 == 0)table[i] = min(table[i], table[i / 3] + 1);
	}

	cout << table[K] << "\n";
}