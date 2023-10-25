#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int Find(vector<int>& numbers, int target)
{
	int start = 0;
	int end = numbers.size() - 1;
	int mid;

	while (start<=end&&start>=0&&end< numbers.size())
	{
		mid = (start + end) / 2;
		if (numbers[mid] > target)
			end = mid - 1;
		else if (numbers[mid] < target)
			start = mid + 1;
		else
			return 1;
	}
	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<int> numbers(N);
	for (int i = 0; i < N; i++)
		cin >> numbers[i];

	sort(numbers.begin(), numbers.end());
	int M,target;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> target;
		cout << Find(numbers, target) << "\n";
	}
}