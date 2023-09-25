#include <iostream>
#include <vector>

using namespace std;
static vector<int> v;
bool isPrime(int value)
{
	if (value < 10)
	{
		if (value == 2 || value == 3 || value == 5 || value == 7)
			return true;
		else
			return false;
	}

	int number = 2;
	int max = value / number;
	while (value % number != 0 && number <= max)
	{
		number++;
		max = value / number;
	}

	if (number > max)
		return true;
	else
		return false;
}

void DFS(int n, int value)
{
	if (n - 1 == 0)
	{
		for (int i = 0; i < 10; i++)
		{
			if (isPrime(value * 10 + i))
				v.push_back(value * 10 + i);
		}
	}
	else
	{
		for (int i = 0; i < 10; i++)
		{
			if (isPrime(value*10 + i))
				DFS(n - 1, value * 10 + i);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	v = vector<int>();

	DFS(N, 0);
	for (int& number : v)
	{
		cout << number << "\n";
	}
}