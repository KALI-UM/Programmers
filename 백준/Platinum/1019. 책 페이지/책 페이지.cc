#include <iostream>
#include <cmath>
#include <string>
#define INF 987654321
using namespace std;
long long NL;
long long Answer[10];

void AddNumbers(long long L)
{
	string S = to_string(L);
	int Digit[11] = { -1,-1,-1,-1,-1,-1, -1,-1,-1, -1,-1 };
	for (int i = S.length() - 1; i >= 0; i--)
		Digit[S.length() - 1 - i] = stoi(S.substr(i, 1));

	int digit = S.length() - 1;
	int d = digit;

	while (d >= 0)
	{
		for (int n = 0; n <= 9; n++)
		{
			if (digit == d && n == 0)continue;
			if (Digit[d] == n)Answer[n] += (L % (long long)pow(10, d)) + 1;
			else if (Digit[d] > n)Answer[n] += (long long)pow(10, d);
		}

		if (d - 1 >= 0)
		{
			for (int n = 0; n <= 9; n++)
				Answer[n] += (Digit[d] + (digit == d ? -1 : 0)) * pow(10, d - 1) * d;
		}

		d--;
	}

	if (digit == 0)return;
	else
		AddNumbers(pow(10, digit) - 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> NL;
	AddNumbers(NL);

	for (int i = 0; i <= 9; i++)
		cout << Answer[i] << ' ';
	cout << '\n';
}