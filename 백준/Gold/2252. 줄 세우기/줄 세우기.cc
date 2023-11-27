#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, E;
	cin >> N >> E;

	vector<vector<int>> list(N + 1, vector<int>());
	vector<int> d(N + 1,0);
	int a, b;
	for (int i = 0; i < E; i++)
	{
		cin >> a >> b;
		list[a].push_back(b);
		d[b]++;
	}

	
	int node = find(d.begin() + 1, d.end(), 0) - d.begin();
	while (node!= N + 1)
	{
		cout << node << ' ';
		d[node] = -1;
		for (int n : list[node])
			d[n]--;

		node = find(d.begin() + 1, d.end(), 0) - d.begin();
	}	
}