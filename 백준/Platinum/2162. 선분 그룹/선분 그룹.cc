#include <iostream>
#include <vector>
using namespace std;

struct L
{
	int x1, y1;
	int x2, y2;
	int group = -1;
};

vector<L>A;

int CCW(int& x1, int& y1, int& x2, int& y2, int& x3, int& y3)
{
	int result = (x1 * y2 + x2 * y3 + x3 * y1) - (x1 * y3 + x2 * y1 + x3 * y2);

	if (result > 0)return 1;
	else if (result < 0) return -1;
	else return 0;
}

bool Cross(L& a, L& b)
{
	int r1 = CCW(a.x1, a.y1, a.x2, a.y2, b.x1, b.y1);
	int r2 = CCW(a.x1, a.y1, a.x2, a.y2, b.x2, b.y2);
	int r3 = CCW(b.x1, b.y1, b.x2, b.y2, a.x1, a.y1);
	int r4 = CCW(b.x1, b.y1, b.x2, b.y2, a.x2, a.y2);

	if (r1 * r2 == 0 && r3 * r4 == 0)
	{
		if (min(a.x1, a.x2) <= max(b.x1, b.x2) && min(b.x1, b.x2) <= max(a.x1, a.x2) && min(a.y1, a.y2) <= max(b.y1, b.y2) && min(b.y1, b.y2) <= max(a.y1, a.y2))
			return true;
		else
			return false;
	}
	else if (r1 * r2 <= 0 && r3 * r4 <= 0)
		return true;
	else
		return false;
}

int Find(int a)
{
	if (A[a].group != a)
		return A[a].group = Find(A[a].group);
	else
		return a;
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);

	if (a == b)return;
	if (a > b)swap(a, b);
	A[b].group = a;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	A.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> A[i].x1 >> A[i].y1 >> A[i].x2 >> A[i].y2;
		A[i].group = i;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (Cross(A[i], A[j]))
				Union(i, j);
		}
	}
	vector<int> G(N, 0);
	int Gcnt = 0;
	int Gmax = 0;
	for (int i = 0; i < N; i++)
	{
		int index = Find(A[i].group);
		if (G[index] == 0)Gcnt++;
		G[index]++;
		if (Gmax < G[index])Gmax = G[index];
	}

	cout << Gcnt << "\n";
	cout << Gmax << "\n";
}