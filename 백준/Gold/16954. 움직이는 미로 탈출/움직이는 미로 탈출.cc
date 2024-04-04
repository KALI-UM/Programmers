#include <iostream>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
string Board[9];
bool Visited[9][8];
int Dir[9][2] = { {0,0},{0,1},{0,-1},{1,0},{1,1},{1,-1},{-1,0},{-1,1},{-1,-1} };

bool BFS(queue<pair<int, int>>& q, queue<pair<int, int>>& nextq)
{
	fill(&Visited[0][0], &Visited[8][8], false);
	while (!q.empty())
	{
		int R = q.front().first;
		int C = q.front().second;
		q.pop();
		for (int d = 0; d < 9; d++)
		{
			int nextR = R + Dir[d][0];
			int nextC = C + Dir[d][1];
			if (nextR >= 0 && nextR < 9 && nextC >= 0 && nextC < 8 && Board[nextR][nextC] != '#' && !Visited[nextR][nextC])
			{
				Visited[nextR][nextC] = true;
				if (nextR == 0 || (nextR == 1 && nextC == 7))
				{
					return true;
				}
				else if (nextR - 1 >= 0 && Board[nextR - 1][nextC] != '#')
				{
					nextq.push({ nextR - 1,nextC });
				}
			}
		}
	}
	return false;
}

bool DFS()
{
	queue<pair<int, int>> buff1;
	queue<pair<int, int>> buff2;
	queue<pair<int, int>>* q1 = &buff1;
	queue<pair<int, int>>* q2 = &buff2;
	buff1.push({ 8,0 });

	int floor = 8;
	bool result = false;
	while (!result && floor > 0)
	{
		result = BFS(*q1, *q2);
		swap(q1, q2);
		floor--;
	}
	return result;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int door = 0;
	Board[0] = { "........" };
	for (int h = 1; h <= 8; h++)
		cin >> Board[h];

	cout << DFS()<<'\n';
}