#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int T, F;
string A, B;
int G[200001][2];

int Find(int a)
{
	if (G[a][0] == a)return a;
	else return G[a][0] = Find(G[a][0]);
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);
	if (a == b)return;
	if (a > b)swap(a, b);
	G[b][0] = a;
	G[a][1] += G[b][1];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> F;
		for (int i = 0; i < 200001; i++)
		{
			G[i][0] = i;
			G[i][1] = 1;
		}

		unordered_map<string, int> um;
		int index = 1;
		for (int f = 0; f < F; f++)
		{
			cin >> A >> B;
			if (um.find(A) == um.end())
				um.insert({ A, index++ });
			if (um.find(B) == um.end())
				um.insert({ B, index++ });
			Union(um.find(A)->second, um.find(B)->second);
			cout << G[Find(um.find(A)->second)][1] << '\n';
		}
	}
}