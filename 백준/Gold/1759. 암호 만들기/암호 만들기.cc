#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
int L, C;
char Str[15];
char aeiou[5] = { 'a','e','i','o','u' };
bool Comp(char& a, char& b)
{
	return (int)a < (int)b;
}

void DFS(string str, int last)
{
	if (str.length() == L)
	{
		bool vowel = false;
		int consonant = 0;
		for (int i = 0; i < str.length(); i++)
		{
		bool v = false;
			for (int c = 0; c < 5; c++)
			{
				if (str[i] == aeiou[c])
				{
					v = true;
					vowel = true;
					break;
				}
			}
			if (!v)
				consonant++;
		}
		if (consonant >= 2 && vowel)
		{
			cout << str << '\n';
		}
		return;
	}
	else
	{
		for (int i = last; i < C; i++)
		{
			DFS(str + Str[i], i + 1);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> L >> C;
	for (int i = 0; i < C; i++)
		cin >> Str[i];
	sort(&Str[0], &Str[C]);

	DFS("", 0);
}

