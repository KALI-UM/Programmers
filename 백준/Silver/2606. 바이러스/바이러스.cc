#include <iostream>
using namespace std;
int N, E;
int G[101];

int Find(int index)
{
	if (G[index] == index)return index;
	else return G[index] = Find(G[index]);
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);
	if (a > b)swap(a, b);
	G[b] = a;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> E;

	for (int i = 1; i <= N; i++)
		G[i] = i;

	int E1, E2;
	for (int i = 1; i <= E; i++)
	{
		cin >> E1 >> E2;
		Union(E1, E2);
	}

	int Result = 0;
	for (int i = 2; i <= N; i++)
		if (Find(G[i]) == 1)Result++;

	cout << Result << '\n';
}