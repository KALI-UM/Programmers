#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
int N_Weight[31] = { 0, };
long long MaxWeight;
int Result = 0;

void DFS(int start, int end, vector<long long>& part, long long sum)
{
	if (start > end)
	{
		if (MaxWeight >= sum)
			part.push_back(sum);
		return;
	}

	DFS(start + 1, end, part, sum);
	DFS(start + 1, end, part, sum + N_Weight[start]);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> MaxWeight;

	vector<long long> part1;
	vector<long long> part2;
	for (int i = 0; i < N; i++)
	{
		cin >> N_Weight[i];
	}
	DFS(0, N / 2, part1, 0);
	DFS(N / 2 + 1, N - 1, part2, 0);
	sort(part1.begin(), part1.end());
	sort(part2.begin(), part2.end());

	for (int i = 0; i < part1.size(); i++)
	{
		long long leftover = MaxWeight - part1[i];
		int j = upper_bound(part2.begin(), part2.end(), leftover)-part2.begin();
		Result += j;
	}

	cout << Result << '\n';
}

