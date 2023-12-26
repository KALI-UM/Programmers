#include <iostream>
#include <vector>
#include <limits.h>
#include <cmath>
using namespace std;
vector<vector<int>> DP;
vector<int> M;


int GetDP(int i, int j)
{
	if (i == j)
		return DP[i][j] = 0;
	else if (DP[i][j] == INT_MAX)
	{
		if (j - i == 1)
			return DP[i][j] = M[2 * i] * M[2 * j] * M[2 * j + 1];
		else
		{
			int result = INT_MAX;
			for (int s = i; s < j; s++)
				result = min(GetDP(i, s) + GetDP(s + 1, j) + M[2 * i] * M[2 * s+1] * M[2 * j + 1], result);

			return DP[i][j] = result;
		}
	}
	else
		return DP[i][j];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	M = vector<int>(N * 2);
	DP = vector<vector<int>>(N, vector<int>(N, INT_MAX));

	for (int i = 0; i < N * 2; i++)
		cin >> M[i];

	cout << GetDP(0,N-1) << "\n";
}