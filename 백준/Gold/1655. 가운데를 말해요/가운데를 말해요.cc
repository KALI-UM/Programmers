#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int N;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;

	priority_queue<int, vector<int>> Left;
	priority_queue<int, vector<int>, greater<int>> Right;

	int curr;
	for (int i = 0; i < N; i++)
	{
		cin >> curr;
		if (Left.empty() || curr < Left.top())
			Left.push(curr);
		else
			Right.push(curr);

		if (((int)Left.size() - 2) >= (int)Right.size())
		{
			Right.push(Left.top());
			Left.pop();
		}
		else if (((int)Right.size() - 2) >= (int)Left.size())
		{
			Left.push(Right.top());
			Right.pop();
		}

		if (Left.size() == Right.size())
			cout << min(Left.top(), Right.top());
		else
			Left.size() > Right.size() ? cout << Left.top() : cout << Right.top();
		cout << "\n";
	}
}