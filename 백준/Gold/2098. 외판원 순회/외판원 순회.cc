#include <iostream>
#include <cmath>
using namespace std;
int N;
int Max = 16 * 1000000 +1;
int DP[16][1 << 16];
int W[16][16];

int TSP(int c, int v)
{
	if (v == (1 << N) - 1)
		return W[c][0] == 0 ? Max : W[c][0];

	if (DP[c][v] != 0)
		return DP[c][v];
	else
	{
		int m = Max;
		for (int i = 0; i < N; i++)
		{
			if ((v & (1 << i)) == 0 && W[c][i] != 0)
			{
				m = min(m, TSP(i, (v | (1 << i))) + W[c][i]);
			}
		}
		return DP[c][v] = m;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> W[i][j];
	}

	cout << TSP(0, 1) << "\n";


}