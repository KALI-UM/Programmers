#include <iostream>
#include <string>
#include <queue>
using namespace std;
int N, M, P;
string Map[1000];
struct Pos
{
	int dist;
	int r, c;
};
queue<Pos> Castle[2][10];
int Cnt[10];
int Dist[10];
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };

bool BFS(int curr, int next)
{
	fill(&Castle[next][1], &Castle[next][P + 1], queue<Pos>());
	int Add = 0;
	for (int currp = 1; currp <= P; currp++)
	{
		queue<Pos>& currq = Castle[curr][currp];
		while (!currq.empty())
		{
			int dist = currq.front().dist;
			int nowr = currq.front().r;
			int nowc = currq.front().c;
			currq.pop();

			for (int d = 0; d < 4; d++)
			{
				int nextr = nowr + dir[d][0];
				int nextc = nowc + dir[d][1];
				if (nextr >= 0 && nextr < N && nextc >= 0 && nextc < M && Map[nextr][nextc] == '.')
				{
					Cnt[currp]++;
					Map[nextr][nextc] = (char)((int)'0' + currp);
					dist == 1 ? Castle[next][currp].push({ Dist[currp],nextr,nextc }) : Castle[curr][currp].push({ dist - 1,nextr,nextc });
				}
			}
		}
		Add += Castle[next][currp].size();
	}
	return (Add != 0);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> P;

	for (int i = 1; i <= P; i++)
		cin >> Dist[i];

	for (int i = 0; i < N; i++)
	{
		cin >> Map[i];
		for (int j = 0; j < M; j++)
		{
			if (Map[i][j] != '.' && Map[i][j] != '#')
			{
				Castle[0][(int)(Map[i][j] - '0')].push({ Dist[(int)(Map[i][j] - '0')],i,j });
				Cnt[(int)(Map[i][j] - '0')]++;
			}
		}
	}

	int curr = 0;
	int next = 1;
	while (BFS(curr, next))
		swap(curr, next);

	for (int i = 1; i <= P; i++)
		cout << Cnt[i] << ' ';
	cout << '\n';

}