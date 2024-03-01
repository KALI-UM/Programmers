#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <map>

using namespace std;
string temp;
inline string erase(string str)
{
	string answer;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] != '.')
			answer += str[i];
	}
	return answer;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> temp;
	stack<int> bracket;
	vector<pair<int, int>> p;
	map<string, string> answer;
	answer.insert({ temp,temp });


	for (int c = 0; c < temp.length(); c++)
	{
		if (temp[c] == '(')
		{
			bracket.push(c);
		}
		else if (temp[c] == ')')
		{
			p.push_back({ bracket.top(), c });
			bracket.pop();
		}
	}

	for (int i = 0; i < p.size(); i++)
	{
		int as = answer.size();
		auto it = answer.begin();
		auto e = answer.end();
		for (; it!=e; it++)
		{
			string f = (*it).second;
			f[p[i].first] = '.';
			f[p[i].second] = '.';
			answer.insert({ erase(f),f });
		}
	}

	auto it = answer.begin();
	it++;
	for (;it!=answer.end(); it++)
	{
		cout << (*it).first << "\n";
	}
}