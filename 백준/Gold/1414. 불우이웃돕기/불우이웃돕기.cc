#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct Edge
{
	int s, e;
	int w;

	bool operator > (const Edge& e) const
	{
		return w > e.w;
	}
}Edge;

vector<int> u;

int FIND(int node)
{
	if (u[node] == node)return node;

	else return u[node] = FIND(u[node]);
}

void UNION(int node1, int node2)
{
	node1 = FIND(node1);
	node2 = FIND(node2);

	if (node1 == node2) return;

	u[node2] = node1;
}

priority_queue<Edge, vector<Edge>, greater<Edge>> EdgeInfo;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;


	char l;
	int result = 0;
	for (int i = 0; i < N; i++)
	{
		u.push_back(i);
		for (int j = 0; j < N; j++)
		{
			cin >> l;

			if (l == '0')
				continue;

			if (l >= 'a' && l <= 'z')
				l = l - 'a' + 1;
			else if (l >= 'A' && l <= 'Z')
				l = l - 'A' + 27;
			if (i == j)
			{
				result += l;
			}
			else
			EdgeInfo.push(Edge{ i,j,l});
		}
	}

	while (!EdgeInfo.empty())
	{
		Edge now = EdgeInfo.top();
		EdgeInfo.pop();

		if (FIND(now.s) == FIND(now.e))
		{
			result += now.w;
			continue;
		}

		UNION(now.s, now.e);
	}

	for (int i = 1; i < N; i++)
	{
		if (FIND(i - 1) != FIND(i))
		{
			result = -1;
			break;
		}
	}

	cout << result << "\n";
}