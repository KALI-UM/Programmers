#include <iostream>

using namespace std;

int DP[1001];
int N;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	DP[0] = 1;
	DP[1] = 1;

	for (int i = 2; i <= N; i++)
		DP[i] = (DP[i - 1] + DP[i - 2] * 2 % 10007) % 10007;

	cout << DP[N] << "\n";

}
