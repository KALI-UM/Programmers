#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> positive;
	vector<int> negative;

	int temp;
	int zero = 1;
	int result = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		if (temp == 1)
			result += 1;
		else if (temp > 0)
			positive.push_back(temp);
		else if (temp < 0)
			negative.push_back(temp);
		else
			zero = 0;
	}

	sort(positive.begin(), positive.end());
	sort(negative.begin(), negative.end());

	if (negative.size() % 2 != 0)
		result += negative.back() * zero;

	for (int i = 0; i < negative.size() / 2; i++)
		result += negative[i * 2] * negative[i * 2 + 1];

	int i = 0;
	if (positive.size() % 2 != 0)
		result += positive[i++];

	for (; i < positive.size();)
		result += positive[i++] * positive[i++];

	cout << result << "\n";
}