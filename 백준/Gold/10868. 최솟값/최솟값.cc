#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<long> tree;
void UpdateTree(int node)
{
	if (node == 1)return;

	tree[node / 2] = min(tree[node / 2 * 2], tree[node / 2 * 2 + 1]);
	UpdateTree(node / 2);
}

long GetMin(int s, int e)
{
	long result = 1000000001;

	while (s <= e)
	{
		if (s % 2 == 1)
		{
			result = min(tree[s], result);
			s++;
		}
		if (e % 2 == 0)
		{
			result = min(tree[e], result);
			e--;
		}

		s = s / 2;
		e = e / 2;
	}
	return result;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int N, M;
	cin >> N >> M;

	int size = 20;
	while (N <= (int)pow(2, size))
		size--;

	size++;
	int leafIndex = (int)pow(2, size);
	tree = vector<long>(leafIndex * 2, 1000000001);
	for (int i = 0; i < N; i++)
		cin >> tree[leafIndex + i];

	int index = leafIndex * 2 - 1;
	while (index > 1)
	{
		tree[index / 2] = min(tree[index], tree[index - 1]);
		index--;
		index--;
	}

	for (int i = 0; i < M; i++)
	{
		long a, b;
		cin >> a >> b;

		cout << GetMin(leafIndex+a-1, leafIndex+b-1) << "\n";
	}

}