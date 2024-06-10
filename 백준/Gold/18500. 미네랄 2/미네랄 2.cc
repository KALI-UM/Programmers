#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;
int R, C, N;
string Cave[101];
int Visited[101][101];
int dir[4][2] = { {1,0}, {0,1 },{-1,0},{0,-1} };

void BFS(int r, int c)
{
	queue<pair<int, int>> q;
	fill(&Visited[0][0], &Visited[99][100], -1);
	Cave[r][c] = '.';

	bool dirGrounded[4] = { false, false, false , false };
	vector<pair<int, int>> cluster[4];
	for (int d = 0; d < 4; d++)
	{
		int nextr = r + dir[d][0];
		int nextc = c + dir[d][1];
		if (nextr >= 0 && nextr < R && nextc >= 0 && nextc < C && Cave[nextr][nextc] == 'x' && Visited[nextr][nextc] == -1)
		{
			q.push({ nextr, nextc });
			Visited[nextr][nextc] = d;
			cluster[d].push_back({ nextr, nextc });
		}
		else
			dirGrounded[d] = true;

		while (!q.empty())
		{
			int nowr = q.front().first;
			int nowc = q.front().second;
			q.pop();

			if (nowr == R - 1)dirGrounded[d] = true;
			for (int d1 = 0; d1 < 4; d1++)
			{
				int nextr1 = nowr + dir[d1][0];
				int nextc1 = nowc + dir[d1][1];
				if (nextr1 >= 0 && nextr1 < R && nextc1 >= 0 && nextc1 < C && Cave[nextr1][nextc1] == 'x' && Visited[nextr1][nextc1] == -1)
				{
					Visited[nextr1][nextc1] = d;
					q.push({ nextr1, nextc1 });
					cluster[d].push_back({ nextr1, nextc1 });
				}
			}
		}

		if (dirGrounded[d] == false)
		{
			int min = 1e9;
			for (int i = 0; i < cluster[d].size(); i++)
			{
				int nowr = cluster[d][i].first;
				int nowc = cluster[d][i].second;
				for (int k = nowr + 1; k <= R; k++)
				{
					if (k == R || (Visited[k][nowc] != d && Cave[k][nowc] == 'x'))
					{
						if (min > (k - nowr - 1))min = k - nowr - 1;
						break;
					}
				}
			}

			for (int i = 0; i < cluster[d].size(); i++)
			{
				int nowr = cluster[d][i].first;
				int nowc = cluster[d][i].second;
				Cave[nowr][nowc] = '.';
			}
			for (int i = 0; i < cluster[d].size(); i++)
			{
				int nowr = cluster[d][i].first;
				int nowc = cluster[d][i].second;
				Cave[nowr + min][nowc] = 'x';
			}
			return;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> R >> C;
	for (int i = 0; i < R; i++)
		cin >> Cave[i];

	cin >> N;
	int temp;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;

		if (i % 2 == 0)
		{
			for (int c = 0; c < C; c++)
			{
				if (Cave[R - temp][c] == '.')continue;
				BFS(R - temp, c);
				break;
			}
		}
		else
		{
			for (int c = C - 1; c >= 0; c--)
			{
				if (Cave[R - temp][c] == '.')continue;
				BFS(R - temp, c);
				break;
			}
		}
	}

	for (int i = 0; i < R; i++)
		cout << Cave[i] << '\n';
}

