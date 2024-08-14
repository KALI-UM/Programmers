#include <iostream>
#include <string>
#include <queue>

using namespace std;

string N;
int Alpabet[26] = { 0, };
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N.length(); i++)
	{
		Alpabet[N[i] >= 'a' ? N[i] - 'a' : N[i] - 'A']++;
	}

	priority_queue<pair<int, char>> q;
	for (int i = 0; i < 26; i++)
	{
		q.push({ Alpabet[i], (char)('A' + i) });
	}

	char char0 = q.top().second;
	int num1 = q.top().first; q.pop();
	int	num2 = q.top().first;
	if (num1 == num2)
		cout << "?\n";
	else
		cout << char0 << "\n";
}

