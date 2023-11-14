#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<vector<int>> visited;
vector<int> answer;
int ABC[3];//용량

vector<int> Add(vector<int>& node, int a, int b)
{
	vector<int> result(node);
	if (node[a] + node[b] > ABC[b])
	{
		result[a] = node[a] + node[b] - ABC[b];
		result[b] = ABC[b];
	}
	else
	{
		result[b] = node[a] + node[b];
		result[a] = 0;
	}
	return result;
}

void BFS(vector<int> node)
{
	queue<vector<int>> q;
	q.push(node);
	answer.push_back(node[2]);
	visited.push_back(node);

	while (!q.empty())
	{
		vector<int> nownode = q.front();
		q.pop();

		for (int i = 0; i < 3; i++)
			if (nownode[i] != 0)
			{
				vector<int> temp = Add(nownode, i, (i + 1) % 3);
				if (find(visited.begin(), visited.end(), temp) == visited.end())
				{
					q.push(temp);
					visited.push_back(temp);
					if (temp[0] == 0)answer.push_back(temp[2]);
				}

				temp.clear();
				temp = Add(nownode, i, (i + 2) % 3);
				if (find(visited.begin(), visited.end(), temp) == visited.end())
				{
					q.push(temp);
					visited.push_back(temp);
					if (temp[0] == 0)answer.push_back(temp[2]);
				}
			}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> ABC[0] >> ABC[1] >> ABC[2];

	vector<int> s;
	s = { 0,0,ABC[2] };
	BFS(s);
	sort(answer.begin(), answer.end());
	for (int i : answer)
		cout << i << ' ';
}