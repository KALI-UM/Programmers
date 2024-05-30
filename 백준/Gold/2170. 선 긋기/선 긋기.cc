#include <iostream>
#include <queue>
using namespace std;
int N;

class comp
{
public:
	bool operator()(pair<int, int>& a, pair<int, int>& b)
	{
		return a.first > b.first ? true : a.first == b.first ? a.second < b.second : false;
	}
};
priority_queue<pair<int, int>, vector< pair<int, int>>, comp > line;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	int temp1, temp2;
	for (int i = 0; i < N; i++)
	{
		cin >> temp1 >> temp2;
		line.push({ temp1, temp2 });
	}

	int Result = 0;
	while (!line.empty())
	{
		int currs = line.top().first;
		int curre = line.top().second;
		line.pop();

		while (!line.empty())
		{
			int nexts = line.top().first;
			int nexte = line.top().second;

			if (currs <= nexts && curre >= nexts)
			{
				line.pop();
				if (curre < nexte)curre = nexte;
			}
			else break;
		}
		Result += curre - currs;
	}

	cout << Result << '\n';
}