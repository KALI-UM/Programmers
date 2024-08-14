#include <iostream>
#include <string>

using namespace std;

int N, M;

void PrintSequence(string str)
{
	for (int i = 0; i < str.length() - 1; i++)
		cout << str[i] << ' ';

	cout << str[str.length() - 1] << '\n';
}

void pruning(string temp, int visited)
{
	if (temp.length() == M)
	{
		PrintSequence(temp);
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		if (((1 << i) & visited) == 0)
			pruning(temp + to_string(i), visited | (1 << i));
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	pruning("", 0);
}

