#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

int N,M;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	unordered_map<int, int> numbers;

	int temp;
	for (int n = 0; n < N; n++)
	{
		cin >> temp;
		auto iter = numbers.find(temp);
		if (iter != numbers.end())
		{
			iter->second++;
		}
		else
		{
			numbers.insert({ temp, 1 });
		}
	}

	cin >> M;
	for (int m = 0; m < M; m++)
	{
		cin >> temp;
		auto iter = numbers.find(temp);
		if (iter != numbers.end())
		{
			cout << (*iter).second<<' ';
		}
		else
		{
			cout << 0 << ' ';
		}
	}
	cout << '\n';
}