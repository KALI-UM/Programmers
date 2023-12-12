#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<long long> tree;
long long MOD = 1000000007;
void UpdateTree(int node)
{
	if (node == 1)return;

	tree[node / 2] = tree[node / 2 * 2] % MOD* tree[node / 2 * 2 + 1] % MOD;
	UpdateTree(node / 2);
}

long long GetMultiply(int s, int e)
{
	long long result = 1;

	while (s <= e)
	{
		if (s % 2 == 1)
		{
			result = result * tree[s] % MOD;
			s++;
		}
		if (e % 2 == 0)
		{
			result = result * tree[e] % MOD;
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


	int N, M, K;
	cin >> N >> M >> K;

	int size = 20;
	while (N <= pow(2, size))
		size--;

	size++;
	int leafIndex = (int)pow(2, size);
	tree = vector<long long>(leafIndex * 2, 1);
	for (int i = 0; i < N; i++)
		cin >> tree[leafIndex + i];

	int index = leafIndex * 2 - 1;
	while (index  !=1)
	{
		tree[index / 2] = tree[index / 2] * tree[index] % MOD;
		index--;
	}

	for (int i = 0; i < M + K; i++)
	{
		long long a, b, c;
		cin >> a >> b >> c;

		if (a == 1)
		{
			tree[leafIndex + b - 1] = c;
			UpdateTree(leafIndex + b - 1);
		}
		else
		{
			cout << GetMultiply(leafIndex + b - 1, leafIndex + c - 1) << "\n";
		}
	}

}