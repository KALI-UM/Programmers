#include <iostream>
#include <queue>
using namespace std;
int N, M;
long long Result=0;
priority_queue<long long,vector<long long>, greater<long long>> Card;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	
	long long temp;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		Card.push(temp);
		Result += temp;
	}

	for (int i = 0; i < M; i++)
	{
		long long a = Card.top();
		Card.pop();
		long long b = Card.top();
		Card.pop();
		Result += a + b;
		Card.push(a + b);
		Card.push(a + b);
	}
	cout << Result << '\n';
}