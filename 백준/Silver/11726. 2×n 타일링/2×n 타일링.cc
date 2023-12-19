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
	vector<long> table(K + 1, 1);

	for (int i = 2; i <= K; i++)
		table[i] = (table[i - 1]+ table[i - 2] )% 10007;

	cout << table[K] << "\n";
}