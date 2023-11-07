#include <iostream>
#include <cmath>

using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long M;
	cin >> M;
	long result = M;

	for (long p = 2; p <= sqrt(M); p++)
	{
		if (M % p == 0)
		{
			result = result - result / p;
			while (M % p == 0)
				M /= p;
		}
	}

	if (M > 1)
		result = result - result / M;

	cout << result << "\n";
}