#include <iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	int A, B;
	for (int i = 0; i < T; i++)
	{
		cin >> A >> B;
		if (A < B)swap(A, B);

		int a = A;int b = B;int result = -1;
		while (result != 0)
		{
			result = a % b;
			a = b;
			b = result;
		}
		cout << A*B/a << "\n";
	}
}