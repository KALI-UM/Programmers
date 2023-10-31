#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	priority_queue<int, vector<int>, greater<int>> q;
	
	int card;
	int result=0;
	for (int i = 0; i < N; i++)
	{
		cin >> card;
		q.push(card);
	}

	while (q.size() != 1)
	{
		int cards = 0;
		cards += q.top(); q.pop();
		cards += q.top(); q.pop();

		result += cards;
		q.push(cards);
	}

	cout << result << "\n";
}