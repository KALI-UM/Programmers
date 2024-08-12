#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;

	vector<int> DP = vector<int>(N + 1, 0);

	DP[1] = 3;
	DP[2] = 7;
	for (int i = 3; i <= N; i++)
	{
		DP[i] = (2 * DP[i - 1] % 9901 + DP[i - 2] % 9901) % 9901;
	}
	cout << DP[N] << "\n";
}
