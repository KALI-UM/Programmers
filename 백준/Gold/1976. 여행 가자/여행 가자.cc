#include <iostream>
#include <vector>
using namespace std;

int N, D;
vector<int> V;
int Find(int node)
{
	//while (node != V[node])
	//	node = V[node];
	//return node;

	if (node == V[node])return node;
	else
		return V[node] = Find(V[node]);
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

	cin >> N >> D;

	V = vector<int>(N + 1);
	for (int i = 1; i <= N; i++)
		V[i] = i;

	int input;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> input;
			if (input == 1)
				UNION(i, j);
		}
	}

	vector<int> city(D);
	cin >> city[0];
	bool success = true;
	for (int i = 1; i < D; i++)
	{
		cin >> city[i];
		if (Find(city[i - 1]) != Find(city[i]))
		{
			cout << "NO" << "\n";
			success = false;
			break;
		}
	}

	if (success)cout << "YES" << "\n";

}