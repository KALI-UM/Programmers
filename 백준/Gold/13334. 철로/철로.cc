#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, D;
struct comp
{
	bool operator()(pair<int, int>& a, pair<int, int>& b)
	{
		return a.second < b.second ? true : a.second == b.second ? a.first < b.first : false;
	}
};

vector<pair<int, int>> Edge;

priority_queue<int, vector<int>, greater<int>> Rail;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	Edge.resize(N);
	int e1, e2;
	for (int i = 0; i < N; i++)
	{
		cin >> e1 >> e2;
		if (e1 > e2)swap(e1, e2);
		Edge[i] = { e1, e2 };
	}
	cin >> D;

	sort(Edge.begin(), Edge.end(), comp());

	int start, end;
	int currcnt = 0, maxcnt = 0;
	for (int i = 0; i < N; i++)
	{
		end = Edge[i].second;
		start = end - D;

		while (!Rail.empty() && Rail.top() < start)
		{
			currcnt--;
			Rail.pop();
		}

		if (Edge[i].first >= start)
		{
			currcnt++;
			Rail.push(Edge[i].first);
			if (currcnt > maxcnt)maxcnt = currcnt;
		}
	}

	cout << maxcnt << '\n';

}

