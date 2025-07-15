#include <iostream>
#include <vector>
#include <algorithm>
int N;

using namespace std;
int main()
{

	cin >> N;
	vector<int> numbers(N);
	for (int i = 0; i < N; i++)
	{
		cin >> numbers[i];
	}

	sort(numbers.begin(), numbers.end());

	for (int i = 0; i < N; i++)
	{
		cout << numbers[i] << '\n';
	}
	
}
