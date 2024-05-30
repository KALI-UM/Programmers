#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string S;
string T;

bool DFS(string& curr)
{
	if (curr.length() == S.length())
		return (curr.compare(S)==0);

	string next = curr.substr(0, curr.length() - 1);
	if (curr.back() == 'B')
		reverse(next.begin(), next.end());
	return DFS(next);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> S >> T;
	cout << DFS(T) << '\n';
}