#include <iostream>
#include <cmath>

using namespace std;
int K;
int A[1000001];
long long tree[500001 * 4];
long long answer = 0;

long long getTree(int node, int start, int end, int left, int right)
{
	if (start > right || end < left)
		return 0;
	if (start >= left && end <= right)
		return tree[node];

	int mid = (start + end) / 2;
	return getTree(node * 2, start, mid, left, right) + getTree(node * 2 + 1, mid + 1, end, left, right);
}

void updateTree(int node)
{
	if (node == 0)return;

	tree[node] += 1;
	updateTree(node / 2);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> K;
	int temp;
	for (int i = 0; i < K; i++)
	{
		cin >> temp;
		A[temp] = i;
	}

	int k = pow(2, ceil(log2(K)));
	for (int i = 0; i < K; i++)
	{
		cin >> temp;
		int j = A[temp] + k;
		answer += getTree(1, k, 2*k-1, j + 1, k + K - 1);
		updateTree(j);
	}

	cout << answer << "\n";
}