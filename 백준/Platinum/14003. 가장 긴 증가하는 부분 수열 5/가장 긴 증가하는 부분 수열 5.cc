#include <iostream>
#include <vector>

using namespace std;
int N;
vector<int> A;
int B[1000001];
int D[1000001];


int binary_search(int target, int s, int e)
{
	int mid;
	while (s != e)
	{
		mid = (s + e) / 2;

		if (B[mid] < target)
			s = mid + 1;
		else
			e = mid;
	}
	return s;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	A.resize(N);
	for (int i = 0; i < N; i++)
		cin >> A[i];

	B[0] = A[0];
	D[0] = 0;

	int max_Index = 0;
	for (int i = 1; i < N; i++)
	{
		if (A[i] > B[max_Index])
		{
			D[i] = ++max_Index;
			B[max_Index] = A[i];
		}
		else if (A[i] == B[max_Index])
		{
			D[i] = max_Index;
		}
		else
		{
			binary_search(A[i], 0, max_Index);
			D[i] = binary_search(A[i], 0, max_Index);
			B[D[i]] = A[i];
		}
	}

	cout << max_Index + 1 << "\n";
	vector<int> answer(max_Index + 1);
	int x = B[max_Index] + 1;
	int index = max_Index;

	for (int i = N - 1; i >= 0; i--)
	{
		if (A[i] < x && D[i] == index)
		{
			answer[index] = A[i];
			index--;
			x = A[i];
		}
	}

	for (int a : answer)
		cout << a << ' ';
}