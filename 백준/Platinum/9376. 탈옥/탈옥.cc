#include <iostream>
#include <vector>
#include <deque>
#include <string.h>
using namespace std;

int dist[3][102][102];
char map[102][102];
int T, H, W;

void BFS(int p, int r, int c)
{
	deque<pair<int, int>> q;
	q.push_back({ r, c });
	dist[p][r][c] = 0;
	int dr[4] = { 0,1,0,-1 };
	int dc[4] = { 1,0,-1,0 };

	while (!q.empty())
	{
		int nowR = q.front().first;
		int nowC = q.front().second;
		q.pop_front();

		for (int d = 0; d < 4; d++)
		{
			int rdr = nowR + dr[d];
			int cdc = nowC + dc[d];

			if (rdr >= 0 && rdr < (H + 2) && cdc >= 0 && cdc < (W + 2) && dist[p][rdr][cdc] == -1)
			{
				if (map[rdr][cdc] == '.' || map[rdr][cdc] == '$')
				{
					dist[p][rdr][cdc] = dist[p][nowR][nowC];
					q.push_front({ rdr, cdc });
				}
				else if (map[rdr][cdc] == '#')
				{
					dist[p][rdr][cdc] = dist[p][nowR][nowC] + 1;
					q.push_back({ rdr, cdc });
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
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> H >> W;
		string temp;
		vector<int> prisoner;
		memset(dist, -1, sizeof(dist));
		memset(map, '.', sizeof(map));
		for (int h = 1; h <= H; h++)
		{
			cin >> temp;
			for (int w = 1; w <= W; w++)
			{
				if (temp[w - 1] == '$')
				{
					prisoner.push_back(h);
					prisoner.push_back(w);
				}

				map[h][w] = temp[w - 1];
			}
		}

		BFS(0, prisoner[0], prisoner[1]);
		BFS(1, prisoner[2], prisoner[3]);
		BFS(2, 0, 0);

		int Dcnt = 100000;
		for (int h = 0; h < (H + 2); h++)
		{
			for (int w = 0; w < (W + 2); w++)
			{
				if (map[h][w] != '*' && dist[0][h][w] != -1 && dist[1][h][w] != -1 && dist[2][h][w] != -1)
				{
					int k = dist[0][h][w] + dist[1][h][w] + dist[2][h][w];
					if (map[h][w] == '#')k = k - 2;
					if (Dcnt > k)Dcnt = k;
				}
			}
		}
		cout << Dcnt << '\n';
	}
}