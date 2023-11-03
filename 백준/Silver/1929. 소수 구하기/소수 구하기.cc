#include <iostream>
#include <vector>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<bool> numbers(M + 1, true);
	numbers[1] = false;
	for (int i = 2; i < M + 1; i++)
	{
		if (numbers[i] == true)
			for (int j = 2; j < M / i + 1; j++)
				numbers[i * j] = false;
	}

	for (int i = N; i <= M; i++)
		if (numbers[i] == true)
			cout << i << "\n";
}