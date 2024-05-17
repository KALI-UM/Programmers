#include <iostream>
#include <string>
#include <queue>
#include <stack>
using namespace std;
int N;

pair<int, pair<int, int>> Tile[502][502];
int Connection[250000][6];	//UL,UR,R,L,RL,RR
int Memo[250000];
int Path[250000];

void SetConnection()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N - ((i + 1) % 2); j++)
		{
			int curr = Tile[i][j].first;
			if (i % 2 == 1)
			{
				if (Tile[i][j].second.first == Tile[i - 1][j - 1].second.second)
				{
					Connection[curr][0] = Tile[i - 1][j - 1].first;
					Connection[Tile[i - 1][j - 1].first][5] = curr;
				}
				if (Tile[i][j].second.second == Tile[i - 1][j].second.first)
				{
					Connection[curr][1] = Tile[i - 1][j].first;
					Connection[Tile[i - 1][j].first][4] = curr;
				}
				if (Tile[i][j].second.first == Tile[i + 1][j - 1].second.second)
				{
					Connection[curr][4] = Tile[i + 1][j - 1].first;
					Connection[Tile[i + 1][j - 1].first][1] = curr;
				}
				if (Tile[i][j].second.second == Tile[i + 1][j].second.first)
				{
					Connection[curr][5] = Tile[i + 1][j].first;
					Connection[Tile[i + 1][j].first][0] = curr;
				}
			}
			if (Tile[i][j].second.second == Tile[i][j + 1].second.first)
			{
				Connection[curr][3] = Tile[i][j + 1].first;
				Connection[Tile[i][j + 1].first][2] = curr;
			}
		}
	}
}

void BFS()
{
	//오는데 드는 비용, 타일 번호
	queue<pair<int, int>> q;
	q.push({ 1,1 });
	Memo[1] = 1;

	while (!q.empty())
	{
		int curr = q.front().second;
		int cost = Memo[curr];
		q.pop();

		if (curr == N * N - N / 2)return;

		for (int i = 0; i < 6; i++)
		{
			if (cost + 1 < Memo[Connection[curr][i]])
			{
				q.push({ cost + 1,Connection[curr][i] });
				Memo[Connection[curr][i]] = cost + 1;
				Path[Connection[curr][i]] = curr;
			}
		}
	}
}

void PrintWay()
{
	int curry = N;
	int currx = curry - ((curry + 1) % 2);
	int cost = Memo[Tile[curry][currx].first] - 1;
	stack<int> way;
	while (cost == 1e9 - 1)
	{
		currx = currx - 1;
		if (currx == 0)
		{
			curry--;
			currx = curry - ((curry + 1) % 2);
		}
		cost = Memo[Tile[curry][currx].first] - 1;
	}
	cout << Memo[Tile[curry][currx].first] << '\n';
	int index = Tile[curry][currx].first;
	while (index != 0)
	{
		way.push(index);
		index = Path[index];
	}
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

	int index = 1;
	cin >> N;
	int a, b;
	pair<int, pair<int, int>> temp;
	fill(&Tile[0][0], &Tile[N + 1][N + 2], temp);
	fill(&Memo[1], &Memo[N * N], 1e9);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N - ((i + 1) % 2); j++)
		{
			cin >> a >> b;
			Tile[i][j] = { index++, {a,b} };
		}
	}
	SetConnection();
	BFS();
	PrintWay();
}