#include <iostream>
#include <unordered_map>
int N, M;

using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	unordered_map<int, int> mods;
	long long  sum = 0;
	long long result = 0;
	long long number;
	for (int i = 1; i <= N; i++)
	{
		cin >> number;
		sum += number;
		sum %= (long long)M;

		auto iter = mods.find(sum);
		if (iter != mods.end())
		{
			result += iter->second++;
		}
		else
		{
			mods[sum] = 1;
		}
	}

	auto iter = mods.find(0);
	if (iter != mods.end())
	{
		result += iter->second;
	}
	cout << result << '\n';

}
