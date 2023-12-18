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

	vector<int> table(K + 1, 0); table[1] = 1;
	for (int i = 2; i < table.size(); i++)
		table[i] = table[i - 1] + table[i - 2];

	cout << table[K] << "\n";


}