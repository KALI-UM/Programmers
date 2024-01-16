#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int R, C, N;
int v = 1;

vector<vector<int>> M;
bool comp(pair<int, int>& a, pair<int, int>& b)
{
	return	a.second == b.second ? a.first > b.first : a.second < b.second;
}

void MineralUpdate(int r, int c)
{
	M[r][c] = 0;

	int dr[4] = { 0, 1, 0, -1 };
	int dc[4] = { 1, 0, -1, 0 };
	//근접한 미네랄이 있다면 업데이트 필요
	queue <pair<int, int>> q;
	vector<vector<pair<int, int>>> cluster(4);
	for (int i = 0; i < 4; i++)
	{
		int rdr = r + dr[i];
		int cdc = c + dc[i];
		if (rdr >= 0 && rdr < R && cdc >= 0 && cdc < C && M[rdr][cdc] != 0)
		{
			q.emplace(rdr, cdc);
			bool ground = false;
			while (!q.empty())
			{
				int nowr = q.front().first;
				int nowc = q.front().second;
				q.pop();

				if (M[nowr][nowc] >= v && M[nowr][nowc] <= v + 3)
				{
					if (M[nowr][nowc] == v + i)continue;
					else
						break;
				}
				else
				{
					M[nowr][nowc] = v + i;
					if (ground == false)
						cluster[i].push_back(make_pair(nowr, nowc));
				}

				for (int j = 0; j < 4; j++)
				{
					rdr = nowr + dr[j];
					cdc = nowc + dc[j];
					if (rdr >= 0 && rdr < R && cdc >= 0 && cdc < C && M[rdr][cdc] != 0)
					{
						q.emplace(rdr, cdc);
						if (rdr == R - 1)
						{
							ground = true;
							cluster[i].clear();
						}
					}
				}
			}

		}
	}

	//분리된 클러스터를 떨어트린다.
	int cnt = R;
	for (int k = 0; k < 4; k++)
	{
		sort(cluster[k].begin(), cluster[k].end(), comp);
		int now = -1;
		for (pair<int, int>& n : cluster[k])
		{
			if (n.second > now)
			{
				now = n.second;
				for (int h = 1;; h++)
				{
					if (n.first + h >= R || M[n.first + h][n.second] != 0)
					{
						cnt = min(cnt, h - 1);
						break;
					}
				}
			}
		}

		for (pair<int, int>& n : cluster[k])
		{
			M[n.first + cnt][n.second] = 1;
			M[n.first][n.second] = 0;
		}
	}
	v += 4;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C;

	M = vector<vector<int>>(R, vector<int>(C, 0));
	string temp;
	for (int r = 0; r < R; r++)
	{
		cin >> temp;
		for (int c = 0; c < C; c++)
		{
			if (temp[c] == 'x')
				M[r][c] = -1;
		}
	}

	cin >> N;
	int h;
	bool left = true;
	for (int i = 0; i < N; i++)
	{
		cin >> h;
		if (left == true)
		{
			left = false;
			for (int c = 0; c < C; c++)
			{
				if (M[R - h][c] != 0)
				{
					MineralUpdate(R - h, c);
					break;
				}
			}
		}
		else
		{
			left = true;
			for (int c = C - 1; c >= 0; c--)
			{
				if (M[R - h][c] != 0)
				{
					MineralUpdate(R - h, c);
					break;
				}
			}
		}
	}

	for (int r = 0; r < R; r++)
	{
		for (int c = 0; c < C; c++)
		{
			M[r][c] == 0 ? cout << '.' : cout << 'x';
		}
		cout << '\n';
	}
}