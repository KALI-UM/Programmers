#include <iostream>
#include <cmath>
#include <stack>
using namespace std;
int C;
long long Answer;
long long Graph[100001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> C;
	while (C != 0)
	{
		stack<int> S;
		Graph[C] = 0;
		for (int i = 0; i < C; i++)
		{
			cin >> Graph[i];
		}

		for (int i = 0; i <= C; i++)
		{
			if (S.empty() || Graph[S.top()] <= Graph[i])
				S.push(i);
			else
			{
				int s= S.size();
				for (int j = 0; j <s; j++)
				{
					int nowI = S.top();
					S.pop();
					int nextI = S.empty() ? -1 : S.top();
					long long temp = Graph[nowI] * (i - nextI - 1);
					if (Answer < temp)Answer = temp;

					if (S.empty() || Graph[S.top()] <= Graph[i])
						break;
				}
				S.push(i);
			}
		}
		cout << Answer << "\n";
		Answer = 0;
		cin >> C;
	}
}