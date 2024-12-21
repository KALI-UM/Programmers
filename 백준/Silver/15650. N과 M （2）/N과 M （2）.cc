#include <iostream>
#include <string>
#include <vector>
using namespace std;
int N, M;

void DFS(int visited, int depth)
{
	if (depth == M)
	{
		for (int i = 1; i <= N; i++)
		{
			int bit = 1 << i;
			if ((visited & bit) == bit)
			{
				cout << i << " ";
			}
		}
		cout << "\n";
		return;
	}

	int lastbit = 0;
	for (int i = N - M + depth; i > 0; i--)
	{
		int bit = 1 << i;
		if ((visited & bit) == bit)
		{
			lastbit = i;
			break;
		}
	}

	for (int i = lastbit + 1; i <= N - M + depth + 1; i++)
	{
		int bit = 1 << i;
		if ((visited & bit) != bit)
		{
			DFS(visited | bit, depth + 1);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	DFS(0, 0);
}
