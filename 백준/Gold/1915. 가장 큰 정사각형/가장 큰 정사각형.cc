#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int N, M;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	vector<vector<int>> T(N, vector<int>(M, 0));
	for (int n = 0; n < N; n++)
	{
		string temp;
		cin >> temp;
		for (int m = 0; m < M; m++)
		{
			if (temp[m] == '1')
				T[n][m] = 1;
		}
	}

	long result = 0;
	for (int n = 0; n < N; n++)
	{
		for (int m = 0; m < M; m++)
		{
			if (T[n][m] == 1 && m > 0 && n > 0)
			{
				T[n][m] = min(T[n - 1][m - 1], min(T[n - 1][m], T[n][m - 1])) + T[n][m];
			}
			if (result < T[n][m])
				result = (long)T[n][m];
		}
	}
	result = result * result;
	cout << result << "\n";
}