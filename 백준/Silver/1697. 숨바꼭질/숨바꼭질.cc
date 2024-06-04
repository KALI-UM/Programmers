#include <iostream>
#include <set>
#include <queue>
using namespace std;
int N, M;
int BFS()
{
	set<int> memo;
	queue<pair<int, int>> q;
	q.push({ 0,N });
	memo.emplace(N);

	while (!q.empty())
	{
		int t = q.front().first;
		int nowp = q.front().second;
		q.pop();
		
		if (nowp == M)return t;
		if (nowp < M)
		{
			int now1 = nowp + 1;
			if (memo.find(now1) == memo.end())
			{
				q.push({ t + 1, now1 });
				memo.emplace(now1);
			}
			int now3 = nowp * 2;
			if (memo.find(now3) == memo.end())
			{
				q.push({ t + 1, now3 });
				memo.emplace(now3);
			}
		}
		int now2 = nowp - 1;
		if (now2 >= 0 && memo.find(now2) == memo.end())
		{
			q.push({ t + 1, now2 });
			memo.emplace(now2);
		}
	}
	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;

	cout << BFS() << '\n';
}