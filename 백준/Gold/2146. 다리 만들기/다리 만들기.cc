#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N;
int Result = 1e9;
int inputMap[101][101];
int Map[101][101];
int d[4][2] = { {0,-1},{0,1},{-1,0},{1,0} };
vector<queue<pair<int, pair<int, int>>>> edge;

void BFS_G(int g, int r, int c)
{
	queue<pair<int, int>> q;
	q.push({ r,c });

	while (!q.empty())
	{
		int nowR = q.front().first;
		int nowC = q.front().second;
		bool e = false;
		q.pop();

		if (Map[nowR][nowC] != 1e9)continue;
		Map[nowR][nowC] = g;

		for (int dir = 0; dir < 4; dir++)
		{
			int nextR = nowR + d[dir][0];
			int nextC = nowC + d[dir][1];
			if (nextR < N && nextR >= 0 && nextC < N && nextC >= 0)
			{
				if (inputMap[nextR][nextC] == 0)e = true;
				else if (inputMap[nextR][nextC] == 1 && Map[nextR][nextC] == 1e9)
					q.push({ nextR, nextC });
			}
		}
		if(e) edge[g].push({ 0,{nowR,nowC} });
	}
}

void BFS_E()
{
	bool wayMap[101][101];
	for (int g = 1; g < edge.size(); g++)
	{
		auto& q = edge[g];
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				wayMap[i][j] = false;
		bool end = false;

		while (!q.empty()||!end)
		{
			int nowR = q.front().second.first;
			int nowC = q.front().second.second;
			int cost = q.front().first;
			q.pop();

			if (wayMap[nowR][nowC])continue;
			wayMap[nowR][nowC] = true;

			for (int dir = 0; dir < 4; dir++)
			{
				int nextR = nowR + d[dir][0];
				int nextC = nowC + d[dir][1];
				if (nextR < N && nextR >= 0 && nextC < N && nextC >= 0)
				{
					if (Map[nextR][nextC] != g && Map[nextR][nextC] != 0)
					{
						if (Result > cost)Result = cost;
						end = true;
					}
					else if (wayMap[nextR][nextC] == false && Map[nextR][nextC] == 0)
						q.push({ cost + 1, {nextR, nextC} });
				}

			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> inputMap[i][j];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			Map[i][j] = 1e9;

	int group = 1;
	edge.push_back(queue<pair<int, pair<int, int>>>());
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (Map[i][j] != 1e9)continue;
			if (inputMap[i][j] == 1)
			{
				edge.push_back(queue<pair<int, pair<int, int>>>());
				BFS_G(group, i, j);
				group++;
			}
			else Map[i][j] = 0;
		}
	}

	BFS_E();
	cout << Result << '\n';
}