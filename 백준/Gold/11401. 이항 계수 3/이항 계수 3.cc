#include <iostream>
using namespace std;
const long long mod = 1000000007;

long long factorial(long long n, long long e)
{
	long long answer = 1;
	for (int i = n; i > e; i--)
	{
		answer *= i;
		answer %= mod;
	}
	return answer;
}

long long Lpow(long long base, long long  n)
{
	if (n == 0)return 1;
	if (n % 2 > 0)return (Lpow(base, n - 1) * base) % mod;
	else
	{
		long long half = Lpow(base, n / 2) % mod;
		return (half * half) % mod;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long  N, K;
	cin >> N >> K;
	long long top = factorial(N, N - K) % mod;
	long long bottom = Lpow(factorial(K, 1) % mod, mod - 2) % mod;
	long long answer = (top * bottom) % mod;
	cout << answer << "\n";
}