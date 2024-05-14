#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#define INF 987654321
using namespace std;
int T;
string A, B, C;
bool visited[202][202];
typedef pair<int, int > AiBi;

bool BFS()
{
	queue <AiBi> q;
	q.push({ 0,0 });
	fill(&visited[0][0], &visited[A.length() - 1][B.length()], false);
	visited[0][0] = true;

	while (!q.empty())
	{
		int ai = q.front().first;
		int bi = q.front().second;
		int ci = ai + bi + 1;
		q.pop();

		if (ci == C.length())return true;
		if (visited[ai + 1][bi] == false)
		{
			visited[ai + 1][bi] = true;
			if (C[ci] == A[ai + 1])
				q.push({ ai + 1, bi });
		}

		if (visited[ai][bi + 1] == false)
		{
			visited[ai][bi + 1] = true;
			if (C[ci] == B[bi + 1])
				q.push({ ai, bi + 1 });
		}
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> A >> B >> C;
		A = ' ' + A + ' ';
		B = ' ' + B + ' ';
		C = ' ' + C;
		cout << "Data set " << t << ": ";
		BFS() ? cout << "yes\n" : cout << "no\n";
	}
}