#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <climits>

using namespace std;
int N, M;
int S, E;

vector<pair<int, int>> Edge[1001];	//city,cost
int Memo[1001];
int Path[1001];

void BFS()
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;	//cost,city
	q.push({ 0, S });
	Memo[S] = 0;
	Path[S] = 0;
	while (!q.empty())
	{
		int curr = q.top().second;
		int cost = q.top().first;
		q.pop();

		if (curr == E)
			return;

		for (int i = 0; i < Edge[curr].size(); i++)
		{
			int next = Edge[curr][i].first;
			if (cost + Edge[curr][i].second < Memo[next])
			{
				Memo[next] = cost + Edge[curr][i].second;
				Path[next] = curr;
				q.push({ Memo[next],next });
			}
		}
	}
}

void Print()
{
	cout << Memo[E] << '\n';
	stack<int> way;
	int curr = E;
	while (curr != 0)
	{
		way.push(curr);
		curr = Path[curr];
	}
	cout << way.size() << '\n';
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
	fill(&Memo[0], &Memo[N+1], INT_MAX);
	int u, v, c;
	for (int i = 0; i < M; i++)
	{
		cin >> u >> v >> c;
		Edge[u].push_back({ v,c });
	}
	cin >> S >> E;
	BFS();
	Print();
}