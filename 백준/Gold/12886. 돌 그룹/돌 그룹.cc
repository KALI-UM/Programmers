#include <iostream>
#include <queue>
#include <set>
#include <tuple>
using namespace std;
set<tuple<int, int, int>> Memo;

void SortTuple(tuple<int, int, int>& a)
{
	priority_queue<int> q;
	q.push(get<0>(a));
	q.push(get<1>(a));
	q.push(get<2>(a));
	int t0 = q.top(); q.pop();
	int t1 = q.top(); q.pop();
	int t2 = q.top(); q.pop();
	a = { t2,t1,t0 };
}

tuple<int, int, int> XY(tuple<int, int, int>& a, int index)
{
	int X, Y, Z;
	switch (index)
	{
	case 0:
		X = get<0>(a);
		Y = get<1>(a);
		Z = get<2>(a);
		break;
	case 1:
		X = get<0>(a);
		Y = get<2>(a);
		Z = get<1>(a);
		break;
	case 2:
		X = get<1>(a);
		Y = get<2>(a);
		Z = get<0>(a);
		break;
	}

	if (X > Y)swap(X, Y);

	if (X != Y)
	{
		Y = Y - X;
		X = X + X;
	}
	tuple<int, int, int> b = { X,Y,Z };
	SortTuple(b);
	return b;
}

bool BFS(tuple<int, int, int> a)
{
	queue<tuple<int, int, int>> q;
	SortTuple(a);
	q.push(a);
	if (get<0>(a) == get<1>(a) && get<0>(a) == get<2>(a))return true;

	while (!q.empty())
	{
		tuple<int, int, int> nowT = q.front();
		q.pop();
		if (Memo.find(nowT) != Memo.end())continue;
		Memo.insert(nowT);

		for (int t = 0; t < 3; t++)
		{
			tuple<int, int, int> T = XY(nowT, t);
			if (Memo.find(T) == Memo.end())
			{
				if (get<0>(T) == get<1>(T) && get<0>(T) == get<2>(T))return true;
				q.push(T);
			}
		}
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int a, b, c;
	tuple<int, int, int> t;
	cin >> a >> b >> c;
	t = { a,b,c };
	cout << BFS(t) << '\n';
}