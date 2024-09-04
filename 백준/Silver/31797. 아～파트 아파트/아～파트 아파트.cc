#include <iostream>
#include <queue>
using namespace std;

int N, M;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;

	priority_queue<pair<int, int>> apart;

	int result;
	int h1, h2;
	for (int i = 1; i <= M; i++)
	{
		cin >> h1 >> h2;
		apart.push({ -h1, i });
		apart.push({ -h2, i });
	}

	queue<int> apart_sorted;
	while (!apart.empty())
	{
		apart_sorted.push(apart.top().second);
		apart.pop();	
	}

	int floor = 1;
	while (floor!=N)
	{
		apart_sorted.push(apart_sorted.front());
		apart_sorted.pop();
		floor++;
	}

	result = apart_sorted.front();
	cout << result << '\n';
}

