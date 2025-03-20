#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N, M;
int number[1025][1025] = { 0, };
int dp[1025][1025] = { 0, };


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> number[i][j];
			dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] + number[i][j];
		}
	}


	int a, b, c, d;
	int result;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> c >> d;
		result = dp[c][d] - (dp[c][b - 1] + dp[a - 1][d] - dp[a - 1][b - 1]);
		cout << result << "\n";
	}
}


