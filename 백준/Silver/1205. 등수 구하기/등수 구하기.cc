#include <iostream>
#include <vector>

using namespace std;
int N, Score, P;
vector<pair<int, int>> RankList;
int Solve(int s, int e)
{
	if (Score > RankList[s].first)return s;
	if (Score < RankList[e].first)return e + 1;

	int m = (s + e) / 2;
	if (RankList[m].first < Score)
		return Solve(s, m - 1);
	else if (RankList[m].first > Score)
		return Solve(m + 1, e);
	else
	{
		while (m<=N&&Score == RankList[m].first)
		{
			m++;
		}
		return m;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> Score >> P;
	int temp, rank;
	RankList.resize(51);
	RankList[0] = { 2000000001, 0 };

	for (int i = 1; i <= N; i++)
	{
		cin >> temp;
		if (RankList[i - 1].first != temp)
			RankList[i] = { temp, i };
		else
			RankList[i] = { temp, RankList[i - 1].second };
	}
	int result;
	int index = Solve(1, N);
	if (index > P)result = -1;
	else if (RankList[index - 1].first == Score)
		result = RankList[index - 1].second;
	else
		result = index;
	cout << result << '\n';

}

