#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<long> tree;
void UpdateTree(int node)
{
	if (node == 1)return;

	tree[node / 2] = tree[node / 2 * 2] + tree[node / 2 * 2 + 1];
	UpdateTree(node / 2);
}

long GetSum(int s, int e)
{
	long result = 0;

	while (s <= e)
	{
		if (s % 2 == 1)
		{
			result += tree[s];
			s++;
		}
		if (e % 2 == 0)
		{
			result += tree[e];
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
	while (N <= (int)pow(2, size))
		size--;

	size++;
	int leafIndex = (int)pow(2, size);
	tree = vector<long>(leafIndex*2, 0);
	for (int i = 0; i < N; i++)
		cin >> tree[leafIndex+ i];
	
	int index = tree.size() - 1;
	while (index!=1)
	{
		tree[index / 2] += tree[index];
		index--;
	}

	vector<long> result;
	long temp, b, c;
	for (int i = 0; i < M + K; i++)
	{
		cin >> temp >> b >> c;
		if (temp == 1)
		{
			tree[leafIndex + b - 1] = c;
			UpdateTree(leafIndex + b - 1);
		}
		else
		{
			result.push_back(GetSum(leafIndex + b - 1, leafIndex + c - 1));
		}
	}

	for (long r : result)
		cout << r << "\n";
}