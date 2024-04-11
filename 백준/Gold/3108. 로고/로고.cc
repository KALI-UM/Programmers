#include <iostream>
#include <algorithm>
using namespace std;

int N;
struct Ract
{
	int i;
	int x1, y1, x2, y2;
};

Ract Ractangle[1000];
int G[1000];
int Cnt = 0;

int Find(int g)
{
	if (G[g] == g)return g;
	else return G[g] = Find(G[g]);
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);
	if (a > b)swap(a, b);
	G[b] = a;
}

bool Xcomp(const Ract& a, const Ract& b)
{
	return a.x1 < b.x1 ? true : a.x1 == b.x1 ? a.x2 < b.x2 : false;
}

bool Check(Ract& a, Ract& b)
{
	if (a.x1 < b.x1 && a.x2 > b.x2 && a.y1 < b.y1 && a.y2 > b.y2)return false;
	if (a.y2 < b.y1 || a.y1 > b.y2)return false;
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		G[i] = i;
		Ractangle[i].i = i;
		cin >> Ractangle[i].x1 >> Ractangle[i].y1 >> Ractangle[i].x2 >> Ractangle[i].y2;

		if ((Ractangle[i].x1 == 0 || Ractangle[i].x2 == 0) && Ractangle[i].y1 <= 0 && Ractangle[i].y2 >= 0)
			Cnt = -1;
		else if ((Ractangle[i].y1 == 0 || Ractangle[i].y2 == 0) && Ractangle[i].x1 <= 0 && Ractangle[i].x2 >= 0)
			Cnt = -1;
	}

	sort(Ractangle, Ractangle + N, Xcomp);

	for (int i = 0; i < N - 1; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (Ractangle[i].x2 >= Ractangle[j].x1)
			{
				if (Find(Ractangle[i].i) != Find(Ractangle[j].i))
				{
					if (Check(Ractangle[i], Ractangle[j]))
						Union(Ractangle[i].i, Ractangle[j].i);
				}
			}
			else break;
		}
	}

	for (int i = 0; i < N; i++)
	{
		if (Find(G[i]) == i)
			Cnt++;
	}
	cout << Cnt << '\n';
}