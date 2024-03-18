#include <iostream>
using namespace std;
int N, Q;
int numbers[2001];

bool DP[2001][2001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	int p1 = 1;
	int p2 = 2;
	for (int n = 1; n <= N; n++)
	{
		cin >> numbers[n];

		DP[n][n] = true;
		if ((n > p1) && (numbers[n - p1] == numbers[n]))
			DP[n - p1][n] = true;
		if ((n > p2) && (numbers[n - p2] == numbers[n]))
			DP[n - p2][n] = true;
	}

	for (int i = 1; i <= N - 1; i++)
	{
		for (int j = i + 1; j <= N; j++)
		{
			if (DP[i][j])
			{
				int a = i - 1;
				int b = j + 1;
				while(a != 0 && b != N+1 && numbers[a] == numbers[b])
				{
					DP[a][b] = true;
					a--; b++;
				}
			}
		}
	}


	cin >> Q;
	int A, B;
	for (int q = 0; q < Q; q++)
	{
		cin >> A >> B;

		if (DP[A][B] == true)
		{
			cout << 1 << "\n";
		}
		else
		{
			cout << 0 << "\n";
		}
	}
}