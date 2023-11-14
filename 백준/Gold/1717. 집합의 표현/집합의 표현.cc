#include <iostream>
#include <vector>
using namespace std;

int N, Q;
vector<int> V;
int Find(int node)
{
	//while (node != V[node])
	//	node = V[node];
	//return node;

	if (node == V[node])return node;
	else
		return V[node] =Find(V[node]);
}
void UNION(int node1, int node2)
{
	node1 = Find(node1);
	node2 = Find(node2);
	if (node1 == node2)return;

	V[node2] = node1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> Q;
	V.resize(N + 1);
	for (int i = 0; i <= N; i++)
		V[i]=i;

	int a, b, c;
	for (int i = 0; i < Q; i++)
	{
		cin >> a >> b >> c;
		if (a == 0)UNION(b, c);
		else
		{
			if (Find(b) == Find(c))cout << "YES" << "\n";
			else cout << "NO" << "\n";
		}
	}
}