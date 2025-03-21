#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N, M;
int result = 0;
int numbers[15000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> numbers[i];
	}

	sort(numbers, numbers + N);
	int s = 0;
	int e = N - 1;
	while (s < e)
	{
		int sum = numbers[s] + numbers[e];
		if (sum == M)
		{
			e--;
			s++;
			result++;
		}
		else if (sum > M)
		{
			e--;
		}
		else
		{
			s++;
		}
	}
	cout << result << "\n";
}


