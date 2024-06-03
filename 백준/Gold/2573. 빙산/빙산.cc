#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M;
int Ice = 0;
vector<vector<int>>* currMap;
vector<vector<int>>* nextMap;
vector<vector<int>> Map[2];
bool visited[300][300];

int dir[4][2] = { {1, 0}, {0,1}, {-1,0},{0,-1} };

bool melt(vector<vector<int>>& curr, vector<vector<int>>& next)
{
	bool gone = false;
	fill(next.begin(), next.end(), vector<int>(M, 0));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (curr[i][j] != 0)
			{
				int side = 0;
				for (int d = 0; d < 4; d++)
					if (curr[i + dir[d][0]][j + dir[d][1]] == 0)side++;
				next[i][j] = curr[i][j] - side;
				if (next[i][j] <= 0)
				{
					next[i][j] = 0;
					Ice--;
					gone = true;
				}
			}
		}
	}
	return gone;
}

bool IsDivided(vector<vector<int>>& curr)
{
	int cnt = 0;
	queue<pair<int, int>> q;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (curr[i][j] != 0)
			{
				q.push({ i,j });
				while (!q.empty())
				{
					int nowr = q.front().first;
					int nowc = q.front().second;
					q.pop();
					if (visited[nowr][nowc] == true)continue;

					visited[nowr][nowc] = true;
					cnt++;
					for (int d = 0; d < 4; d++)
					{
						if (curr[nowr + dir[d][0]][nowc + dir[d][1]] != 0&& visited[nowr + dir[d][0]][nowc + dir[d][1]]==false)
							q.push({ nowr + dir[d][0] , nowc + dir[d][1] });
					}
				}
				return !(Ice == cnt);
			}
		}
	}
	return !(Ice == cnt);
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		Map[0].push_back(vector<int>(M));
		Map[1].push_back(vector<int>(M));
	}

	currMap = &Map[0];
	nextMap = &Map[1];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> (*currMap)[i][j];
			if ((*currMap)[i][j] != 0)Ice++;
		}
	}

	int Result = 0;
	for (int i = 1; i <= 300; i++)
	{
		if (Ice <=1)break;

		fill(&visited[0][0], &visited[299][300], false);
		if (melt(*currMap, *nextMap))
		{
			if (IsDivided(*nextMap))
			{
				Result = i;
				break;
			}
		}
		swap(nextMap, currMap);
	}
	cout << Result << '\n';
}