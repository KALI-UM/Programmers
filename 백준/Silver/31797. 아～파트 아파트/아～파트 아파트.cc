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

	int floor = 1;
	if(N>2*M)floor+= N - (N % (2 * M));
	while (!apart.empty())
	{
		int curr = apart.top().second;
		apart.pop();
		if (floor == N)
		{
			result = curr;
			break;
		}
		floor++;
	}
	cout << result << '\n';
}

