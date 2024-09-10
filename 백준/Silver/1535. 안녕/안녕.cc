#include <iostream>
#include <algorithm>
using namespace std;

int N;
int Data[21][2];
int DP[101];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> Data[i][0];	//체력
	}
	for (int i = 1; i <= N; i++)
	{
		cin >> Data[i][1];	//기쁨
	}
	int M = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 99 - Data[i][0]; j >= 0; j--)
		{
			DP[j + Data[i][0]] = max(DP[j + Data[i][0]], DP[j] + Data[i][1]);
			M = max(M, DP[j + Data[i][0]]);
		}
	}
	cout << M << '\n';
}

