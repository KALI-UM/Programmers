#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int H, W;
string Board[25];
string Pipe = "1234|-+";
bool Visited[25][25];
int Cnt = 1;
int cnt = 0;
pair<int, int> M;
pair<int, int> Z;
int Dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
pair<int, int> Result;

bool CheckPipe(pair<int, int>& prev, const char pipe)
{
	if (pipe == '+')return true;
	if (pipe == '.') return false;

	if (prev.first == 1 && prev.second == 0)
		return pipe == '|' || pipe == '2' || pipe == '3';
	else if (prev.first == -1 && prev.second == 0)
		return pipe == '|' || pipe == '1' || pipe == '4';
	else if (prev.first == 0 && prev.second == 1)
		return pipe == '-' || pipe == '3' || pipe == '4';
	else if (prev.first == 0 && prev.second == -1)
		return pipe == '-' || pipe == '1' || pipe == '2';
}

pair<int, int> GetDir(pair<int, int>& prev, const char pipe)
{
	if (pipe == '1' || pipe == '3')
		return { prev.second * (-1), prev.first * (-1) };
	else if (pipe == '2' || pipe == '4')
		return { prev.second, prev.first };
	else
		return prev;
}

pair<int, int> FindWay(int R, int C, const char dest)
{
	cnt = 0;
	fill(&Visited[0][0], &Visited[24][25], false);
	pair<int, int> prevDir;
	pair<int, int> nowDir;
	int nowR = R;
	int nowC = C;
	for (int d = 0; d < 4; d++)
	{
		int dr = R + Dir[d][0];
		int dc = C + Dir[d][1];
		if (dr >= 0 && dr < H && dc >= 0 && dc < W && Board[dr][dc] != '.')
		{
			prevDir = { Dir[d][0],Dir[d][1] };
			nowR = dr; nowC = dc;
			break;
		}
	}
	if (nowR == R && nowC == C)
	{
		return{ R,C };
	}

	while (Board[nowR][nowC] != dest && Cnt >= cnt)
	{
		if (!Visited[nowR][nowC])cnt++;
		else if (Board[nowR][nowC] != '+')break;

		Visited[nowR][nowC] = true;

		if (!CheckPipe(prevDir, Board[nowR][nowC]))break;
		nowDir = GetDir(prevDir, Board[nowR][nowC]);
		prevDir = nowDir;
		nowR = nowR + prevDir.first;
		nowC = nowC + prevDir.second;
	}

	return { nowR ,nowC };
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> H >> W;

	for (int h = 0; h < H; h++)
	{
		cin >> Board[h];
		for (int w = 0; w < W; w++)
		{
			if (Board[h][w] == '.')continue;
			if (Board[h][w] == 'M')
			{
				M.first = h; M.second = w;
			}
			else if (Board[h][w] == 'Z')
			{
				Z.first = h; Z.second = w;
			}
			else
				Cnt++;
		}
	}

	Result = FindWay(M.first, M.second, '.');
	if (Board[Result.first][Result.second] == '.')
	{
		for (int i = 0; i < Pipe.length(); i++)
		{
			Board[Result.first][Result.second] = Pipe[i];
			pair<int, int> temp = FindWay(M.first, M.second, 'Z');
			if (Cnt == cnt && temp.first == Z.first && temp.second == Z.second)
			{
				cout << Result.first + 1 << ' ' << Result.second + 1 << ' ' << Pipe[i] << '\n';
				break;
			}
		}
	}
	else
	{
		Result = FindWay(Z.first, Z.second, '.');
		for (int i = 0; i < Pipe.length(); i++)
		{
			Board[Result.first][Result.second] = Pipe[i];
			pair<int, int> temp = FindWay(Z.first, Z.second, 'M');
			if (Cnt == cnt && temp.first == M.first && temp.second == M.second)
			{
				cout << Result.first + 1 << ' ' << Result.second + 1 << ' ' << Pipe[i] << '\n';
				break;
			}
		}
	}
}