#include <iostream>
#include <queue>

using namespace std;
int N;
priority_queue<int> Weight;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;

	int temp;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		Weight.push(temp);
	}

	int Result = 0;
	for (int i = 1; i <= N; i++)
	{
		if (Result < Weight.top() * i) Result = Weight.top() * i;
		Weight.pop();
	}
	cout << Result << '\n';
}