#include <iostream>
#include <queue>
#include <limits.h>
#include <algorithm>

using namespace std;
#define INF INT_MAX
int W, H;

int visited[20][20];
char room[20][20];
int Way[11][11];

int dirt[11][2];
int dir[2][4] = { {1, 0, -1, 0} ,{0, 1, 0, -1} };
int result;
bool impossible = false;

void BFS(int vr, int vc)
{
	fill(&visited[0][0], &visited[19][20], INF);

	queue<pair<int, int>> q;
	q.push({ vr,vc });
	visited[vr][vc] = 0;

	while (!q.empty())
	{
		int nowR = q.front().first;
		int nowC = q.front().second;
		q.pop();

		for (int d = 0; d < 4; d++)
		{
			int dR = nowR + dir[0][d];
			int dC = nowC + dir[1][d];

			if (dR < H && dR >= 0 && dC < W && dC >= 0 && room[dR][dC] != 'x' && visited[dR][dC] == INF)
			{
				visited[dR][dC] = visited[nowR][nowC] + 1;
				q.push({ dR, dC });
			}
		}
	}
}

void GetResult(int dirt, int now, int v, int value)
{
	if (v == ((1 << dirt) - 1))
	{
		result = min(result, value);
		return;
	}

	for (int i = 1; i < dirt; i++)
	{
		if ((v & (1 << i)) != (1 << i))
		{
			GetResult(dirt, i, v | (1 << i), value + Way[now][i]);
		}
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> W >> H;
	while (W != 0 && H != 0)
	{
		int dirt_c = 1;
		result = INF;
		impossible = false;
		//fill(&dirt[0][0], &dirt[10][1], 0);
		//fill(&Way[0][0], &Way[10][11], 0);
		for (int h = 0; h < H; h++)
		{
			cin >> room[h];
			for (int w = 0; w < W; w++)
			{
				if (room[h][w] == '*')
				{
					dirt[dirt_c][0] = h;
					dirt[dirt_c][1] = w;
					dirt_c++;
				}
				else if (room[h][w] == 'o')
				{
					dirt[0][0] = h;
					dirt[0][1] = w;
				}
			}
		}

		for (int d = 0; d < dirt_c; d++)
		{
			BFS(dirt[d][0], dirt[d][1]);

			for (int i = 0; i < dirt_c; i++)
			{
				Way[d][i] = visited[dirt[i][0]][dirt[i][1]];
				if (Way[d][i] == INF)
					impossible = true;
			}
		}
		GetResult(dirt_c, 0, 1, 0);

		if (impossible)result = -1;
		cout << result << "\n";
		cin >> W >> H;
	}

}