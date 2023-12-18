#include <iostream>
using namespace std;
long A, Z;
long D[202][202];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long K;
	cin >> A >> Z >> K;

	for (int i = 0; i <= 200; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (i == j || j == 0)
				D[i][j] = 1;
			else
			{
				D[i][j] = D[i - 1][j] + D[i - 1][j - 1];
				if (D[i][j] > 1000000000)
					D[i][j] = 1000000001;
			}
		}
	}

	if (D[A + Z][Z] < K)
		cout << "-1" << "\n";
	else
	{
		while (A > 0 || Z > 0)
		{
			if (D[A - 1 + Z][Z] >= K)
			{
				A--;
				cout << "a";
			}
			else
			{
				K = K - D[A - 1 + Z][Z];
				Z--;
				cout << "z";
			}
		}
	}

}