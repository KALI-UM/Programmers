#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int K;
	cin >> K;

	vector<int> PayTable(K + 1, 0);
	vector<int> TimeTable(K + 1, 0);
	vector<int> Table(K + 1, 0);
	
	for (int i = 1; i <= K; i++)
	{
		cin >> TimeTable[i] >> PayTable[i];

		Table[i] = max(Table[i], Table[i - 1]);

		if(i+ TimeTable[i]-1<=K)
		Table[i + TimeTable[i] - 1] = max(Table[i -1] + PayTable[i], Table[i + TimeTable[i] - 1]);
	}

	cout << Table[K] << "\n";
}