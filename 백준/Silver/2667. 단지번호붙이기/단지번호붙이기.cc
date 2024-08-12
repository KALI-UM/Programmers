#include <iostream>
#include <string>
#include <queue>
using namespace std;

int N;
string map[25];
bool visited[25][25];

int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

int DFS(int r, int c)
{
	int cnt = 0;
	visited[r][c] = true;
	for (int i = 0; i < 4; i++)
	{
		int nr = r + dir[i][0];
		int nc = c + dir[i][1];
		if (nr >= 0 && nr < N && nc >= 0 && nc < N && !visited[nr][nc] && map[nr][nc] == '1')
			cnt += 1 + DFS(nr, nc);
		
	}
	return cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> map[i];
	}

	priority_queue<int, vector<int>, greater<int>> q;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == '1' && !visited[i][j])
				q.push(DFS(i, j)+1);
		}
	}
	cout << q.size() << "\n";
	while (!q.empty())
	{
		cout << q.top() << "\n";
		q.pop();
	}
}