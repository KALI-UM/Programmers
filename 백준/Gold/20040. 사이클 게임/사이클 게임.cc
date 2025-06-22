#include <iostream>
#include <vector>
using namespace std;

int N, M;
int result;
vector<int> group;

int Find(int a)
{
	while (group[a] != a)
	{
		a = group[a];
	}
	return a;
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);

	if (a > b)
	{
		swap(a, b);
	}

	group[b] = a;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	group = vector<int>(N);
	for (int i = 0; i < N; i++)
	{
		group[i] = i;
	}

	
	int temp1, temp2;
	for (int i = 0; i < M; i++)
	{
		cin >> temp1 >> temp2;
		if (Find(temp1) == Find(temp2))
		{
			result = i + 1;
			break;
		}
		Union(temp1, temp2);
	}

	cout << result << '\n';
}
