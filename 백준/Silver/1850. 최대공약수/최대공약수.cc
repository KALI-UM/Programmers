#include <iostream>

long long  gcd(long long a, long long b)
{
	if (a % b != 0)
		return gcd(b, a % b);
	else
		return b;
}

using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long A, B;
	cin >> A >> B;


	if (A < B)swap(A, B);
	long long result = gcd(A, B);


	for (long long  i = 0; i < result; i++)
		cout << "1";

	cout << "\n";
}