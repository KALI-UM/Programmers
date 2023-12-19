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
	vector<long> table(91, 0);

	if (K == 1)
		cout << 1 << "\n";

	else
	{
		table[1] = 2;	//계산을 위해 예외를 둔다.
		table[2] = 1;
		table[3] = 2;

		for (int i = 4; i <= K; i++)
			table[i] = table[i - 1] + table[i - 2];

		cout << table[K] << "\n";
	}
}