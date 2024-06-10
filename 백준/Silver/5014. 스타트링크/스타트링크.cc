#include <iostream>
#include <string>
#include <queue>
using namespace std;
int F, S, G, U, D;

int Floor[1000001];
void BFS()
{
	queue<int> q;
	q.push(S);

	fill(&Floor[1], &Floor[F + 1], 1e9);
	Floor[S] = 0;
	while (!q.empty())
	{
		int curr = q.front();
		q.pop();
		if (curr == G)return;
		int up = curr + U;
		int down = curr - D;
		if (up <= F && Floor[up] == 1e9)
		{
			Floor[up] = Floor[curr] + 1;
			q.push(up);
		}
		if (down >= 1 && Floor[down] == 1e9)
		{
			Floor[down] = Floor[curr] + 1;
			q.push(down);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> F >> S >> G >> U >> D;
	BFS();
	Floor[G] == 1e9 ? cout << "use the stairs" << '\n' : cout << Floor[G] << '\n';
}

