#include <iostream>
#include <limits.h>
#include <algorithm>
#include <cmath>

using namespace std;
int K;
int Q;
int tree[100001 * 4];

int getTree(int node, int start, int end, int left, int right)
{
	if (start > right || end < left)
		return INT_MAX;
	if (start >= left && end <= right)
		return tree[node];

	int mid = (start + end) / 2;
	int L = getTree(node * 2, start, mid, left, right);
	int R = getTree(node * 2 + 1, mid + 1, end, left, right);
	return  L < R ? L : R;
}

void updateTree(int node, int value)
{
	if (tree[node] == value)return;

	tree[node] = value;
	if (node == 1)return;

	int sibling = node + 1 - 2 * (node % 2);

	tree[node] < tree[sibling]?
		updateTree(node / 2, tree[node]): updateTree(node / 2, tree[sibling]);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> K;
	int k = pow(2, ceil(log2(K)));
	fill(&tree[0], &tree[2 * k], INT_MAX);
	for (int i = k; i < k + K; i++)
	{
		int temp;
		cin >> temp;
		updateTree(i, temp);
	}

	cin >> Q;
	for (int i = 0; i < Q; i++)
	{
		int q, a, b;
		cin >> q >> a >> b;
		if (q == 1)
			updateTree(k + a-1, b);
		else
			cout << getTree(1, k, 2 * k - 1, k + a-1, k + b-1) << "\n";
	}
}