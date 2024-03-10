#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;
#define INF 1e9

int W, H;
char Map[101][101];
int visited[4][101][101];
int C[2][2];
int d[2][4] = { {0,1,0,-1},{1,0,-1,0} };

void A(int r, int c)
{
	queue <tuple<int, int, int>> q;
	q.push({ 0,r,c });
	q.push({ 1,r,c });
	q.push({ 2,r,c });
	q.push({ 3,r,c });
	visited[0][r][c] = -1;
	visited[1][r][c] = -1;
	visited[2][r][c] = -1;
	visited[3][r][c] = -1;

	while (!q.empty())
	{
		int passedDir = get<0>(q.front());
		int nowR = get<1>(q.front());
		int nowC = get<2>(q.front());
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int rd = nowR + d[0][i];
			int cd = nowC + d[1][i];

			while (rd < H && cd < W && rd >= 0 && cd >= 0 && Map[rd][cd] != '*' && visited[i][rd][cd] == INF && i != passedDir)
			{
				if (visited[i][rd][cd] > (visited[passedDir][nowR][nowC] + 1)) visited[i][rd][cd] = visited[passedDir][nowR][nowC] + 1;
				q.push({ i, rd,cd });

				rd += d[0][i];
				cd += d[1][i];
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> W >> H;

	fill(&visited[0][0][0], &visited[3][100][101], INF);

	int start = 0;
	for (int r = 0; r < H; r++)
	{
		cin >> Map[r];
		for (int c = 0; c < W; c++)
		{
			if (Map[r][c] == 'C')
			{
				C[start][0] = r;
				C[start][1] = c;
				start++;
			}
		}
	}

	A(C[0][0], C[0][1]);
	int result = INF;
	if (result > visited[0][C[1][0]][C[1][1]]) result = visited[0][C[1][0]][C[1][1]];
	if (result > visited[1][C[1][0]][C[1][1]]) result = visited[1][C[1][0]][C[1][1]];
	if (result > visited[2][C[1][0]][C[1][1]]) result = visited[2][C[1][0]][C[1][1]];
	if (result > visited[3][C[1][0]][C[1][1]]) result = visited[3][C[1][0]][C[1][1]];
	cout << result << "\n";
}