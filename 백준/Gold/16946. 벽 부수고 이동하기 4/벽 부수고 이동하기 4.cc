#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
int N, M;
int Board[1000][1000];
int Visited[1000][1000];
int Dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int G[1000000] = { 0, };

int BFS(int g, int r, int c)
{
	int cnt = 0;
	queue<pair<int, int>> q;
	q.push({ r,c });

	while (!q.empty())
	{
		int nowR = q.front().first;
		int nowC = q.front().second;
		q.pop();

		if (Visited[nowR][nowC] != 0)continue;
		Visited[nowR][nowC] = g;
		cnt++;

		for (int d = 0; d < 4; d++)
		{
			int rd = nowR + Dir[d][0];
			int cd = nowC + Dir[d][1];
			if (rd >= 0 && rd < N && cd >= 0 && cd < M && Board[rd][cd] == 0 && Visited[rd][cd] == 0)
				q.push({ rd,cd });
		}
	}
	return cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	string temp;
	for (int n = 0; n < N; n++)
	{
		cin >> temp;
		for (int m = 0; m < M; m++)
		{
			if (temp[m] == '1')
				Board[n][m] = 1;
			else
				Board[n][m] = 0;
		}
	}

	int g = 1;
	for (int n = 0; n < N; n++)
	{
		for (int m = 0; m < M; m++)
		{
			if (Visited[n][m] == 0 && Board[n][m] == 0)
			{
				G[g] = BFS(g, n, m);
				g++;
			}
		}
	}

	for (int n = 0; n < N; n++)
	{
		for (int m = 0; m < M; m++)
		{
			if (Board[n][m] == 1)
			{
				int D[4] = { 0, };
				for (int d = 0; d < 4; d++)
				{
					int rd = n + Dir[d][0];
					int cd = m + Dir[d][1];
					if (rd >= 0 && rd < N && cd >= 0 && cd < M)
					{
						D[d] = Visited[rd][cd];
					}
				}
				Board[n][m] += G[D[0]];
				if (D[0] != D[1])
					Board[n][m] += G[D[1]];
				if (D[0] != D[2] && D[1] != D[2])
					Board[n][m] += G[D[2]];
				if (D[0] != D[3] && D[1] != D[3] && D[2] != D[3])
					Board[n][m] += G[D[3]];
			}
			cout << Board[n][m]%10;
		}
		cout << '\n';
	}
}