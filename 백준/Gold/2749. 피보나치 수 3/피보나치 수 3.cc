#include <iostream>
#include <map>
using namespace std;
long long mod = 1000000;
map<long long, long long> fibo_m;

long long fibo(long long n)
{
	if (fibo_m.find(n) != fibo_m.end())	return fibo_m[n];

	else
	{
		if (n % 2 != 0)
		{
			long long half = fibo((n + 1) / 2);
			long long halfm1 = fibo((n + 1) / 2 - 1);

			long long temp = ((half*half%mod) + (halfm1*halfm1%mod)) % mod;

			fibo_m.emplace(n, temp);
			return temp;
		}
		else
		{
			long long half = fibo(n / 2);
			long long halfm1 = fibo(n / 2 - 1);

			long long temp = (half + halfm1 * 2 % mod) % mod;
			temp = temp * half % mod;

			fibo_m.emplace(n, temp);
			return temp;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	fibo_m.emplace(0, 1);
	fibo_m.emplace(1, 1);
	fibo_m.emplace(2, 1);
	fibo_m.emplace(3, 2);
	fibo_m.emplace(4, 3);

	long long A;
	cin >> A;

	cout << fibo(A);
}