#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	vector<int> numbers(N);
	vector<int> L(N);
	vector<int> R(N);
	for (int i = 0; i < N; i++)
		cin >> numbers[i];

	L[0] = numbers[0];
	R[N - 1] = numbers[N - 1];

	int result = L[0];
	for (int i = 1; i < N; i++)
	{
		L[i] = max(L[i - 1] + numbers[i], numbers[i]);
		result = max(L[i], result);
	}

	for (int i = N - 2; i >= 0; i--)
	{
		R[i] = max(R[i + 1] + numbers[i], numbers[i]);
		result = max(R[i], result);
	}

	for (int i = 1; i < N-1; i++)
		result = max(result, L[i - 1] + R[i + 1]);

	cout << result << "\n";
}