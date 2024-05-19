#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <climits>

using namespace std;
int N, M;
int Memo[200001];
int Path[200001];

void BFS()
{
	queue<pair<int, int>> q;	//cost, pos
	q.push({ 0,N });
	Memo[N] = 0;
	Path[N] = -1;

	while (!q.empty())
	{
		int curr = q.front().second;
		int cost = Memo[curr];
		q.pop();
		if (curr == M)return;
		if (curr < M)
		{
			if (cost + 1 < Memo[curr + 1])
			{
				q.push({ cost + 1, curr + 1 });
				Memo[curr + 1] = cost + 1;
				Path[curr + 1] = curr;
			}
			if (cost + 1 < Memo[curr * 2])
			{
				q.push({ cost + 1, curr * 2 });
				Memo[curr * 2] = cost + 1;
				Path[curr * 2] = curr;
			}
		}
		if (curr - 1 >= 0)
		{
			if ((cost + 1 < Memo[curr - 1]))
			{
				q.push({ cost + 1, curr - 1 });
				Memo[curr - 1] = cost + 1;
				Path[curr - 1] = curr;
			}
		}
	}
}

void Print()
{
	stack<int> way;
	int curr = M;
	while (curr != -1)
	{
		way.push(curr);
		curr = Path[curr];
	}
	cout << way.size() - 1 << '\n';
	while (!way.empty())
	{
		cout << way.top() << ' ';
		way.pop();
	}
	cout << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	fill(&Memo[0], &Memo[2 * (N > M ? N : M) + 1], INT_MAX);
	BFS();
	Print();
}