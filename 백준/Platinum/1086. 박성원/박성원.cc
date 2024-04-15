#include <iostream>
#include <cmath>
#include <string>
#include <set>

using namespace std;
int N, K;
string Numbers[15];
int NumberK[15];
int Mod10K[51];
long long DP[1 << 15][101] = { 0, };

inline int GetMod10K(int d)
{
	if (Mod10K[d] != -1)return Mod10K[d];

	if (d >= 10)
	{
		return Mod10K[d] = ((GetMod10K(d - 9) * GetMod10K(9)) % K);
	}
	else
	{
		int t = pow(10, d);
		return t % K;
	}
}

inline long long gcd(long long a, long long b)
{
	if (b == 0)return a;
	else return gcd(b, a % b);
}

inline int GetModK(string str)
{
	int result = 0;
	int s = 0;
	int offset = 9;
	int t;
	while (str.length() > s)
	{
		if (s + offset > str.length())
			offset = str.length() - s;

		t = GetMod10K(str.length() - s - offset);
		result += ((stoi(str.substr(s, offset)) % K) * t) % K;
		result %= K;
		s = s + offset;
	}
	return result;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> Numbers[i];
	cin >> K;

	fill(&Mod10K[0], &Mod10K[51], -1);

	for (int i = 0; i < N; i++)
		NumberK[i] = GetModK(Numbers[i]);

	DP[0][0] = 1;
	for (int i = 0; i < (1 << N); i++)
	{
		for (int j = 0; j < N; j++)
		{
			if ((i & (1 << j)) == 0)
			{
				int next = (i | (1 << j));
				for (int k = 0; k < K; k++)
					DP[next][((k * GetMod10K(Numbers[j].length()) % K) + NumberK[j]) % K] += (long long)DP[i][k]; //ㅋㅋㅋㅋ DP[next][temp] =+ DP[i][k];일케써놓고 한참헤맨 바보가,,,여깃네,,,
			}
		}
	}

	long long p = DP[(1 << N) - 1][0];
	long long q = 1;
	for (int i = 1; i <= N; i++)
		q *= (long long)i;

	if (p == 0)
		q = 1;
	else
	{
		long long g = gcd(q, p);
		p /= g;
		q /= g;
	}
	cout << p << '/' << q << '\n';

}