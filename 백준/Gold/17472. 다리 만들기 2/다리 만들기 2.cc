#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//최소신장트리
struct Edge
{
	int s, e;
	int w;
	bool operator> (const Edge& temp) const {
		return w > temp.w;
	}
};

vector<vector<int>> Map;
vector<int> u;

vector<vector<pair<int, int>>> sumlist;
priority_queue<Edge, vector<Edge>, greater<Edge>> EdgeInfo;

int FIND(int node)
{
	if (u[node] == node)return node;

	else return u[node] = FIND(u[node]);
}

void UNION(int node1, int node2)
{
	node1 = FIND(node1);
	node2 = FIND(node2);

	if (node1 == node2)return;
	u[node2] = node1;
}

void BFS(int group, int nodeR, int nodeC)
{
	queue<pair<int, int>> q;
	q.emplace(nodeR, nodeC);

	int dr[4] = { 0,1,0,-1 };
	int dc[4] = { -1,0,1,0 };

	while (!q.empty())
	{
		int r = q.front().first;
		int c = q.front().second;
		q.pop();


		if (Map[r][c] != -1) continue;
		Map[r][c] = group;
		sumlist[group].push_back(make_pair(r, c));

		for (int i = 0; i < 4; i++)
		{
			int rdr = r + dr[i];
			int cdc = c + dc[i];
			if (cdc >= 0 && cdc < Map[0].size() && rdr >= 0 && rdr < Map.size())
			{
				if (Map[rdr][cdc] == -1)
					q.emplace(rdr, cdc);
			}
		}
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int row, col;
	cin >> row >> col;
	Map = vector<vector<int>>(row, vector<int>(col, 0));

	int k;
	for (int r = 0; r < row; r++)
	{
		for (int c = 0; c < col; c++)
		{
			cin >> k;
			if (k == 1)Map[r][c] = -1;
		}
	}

	int gn = 1;
	u.push_back(0);
	sumlist.push_back(vector<pair<int, int>>());
	for (int r = 0; r < row; r++)
	{
		for (int c = 0; c < col; c++)
		{
			if (Map[r][c] == -1)
			{
				sumlist.push_back(vector<pair<int, int>>());
				BFS(gn, r, c);
				u.push_back(gn);
				gn++;
			}
		}
	}

	for (int i = 1; i < sumlist.size(); i++)
	{
		vector<pair<int, int>> now = sumlist[i];

		for (int j = 0; j < now.size(); j++)
		{
			int r = now[j].first;
			int c = now[j].second;
			int nowG = Map[r][c];

			int dr[4] = { 0,1,0,-1 };
			int dc[4] = { -1,0,1,0 };
			for (int d = 0; d < 4; d++)
			{
				int rdr = r + dr[d];
				int cdc = c + dc[d];
				int blenght = 0;

				while (rdr >= 0 && rdr < Map.size() && cdc >= 0 && cdc < Map[0].size())
				{
					if (Map[rdr][cdc] == nowG)
						break;
					else if (Map[rdr][cdc] != 0)
					{
						if (blenght >= 2)
							EdgeInfo.push(Edge{ nowG, Map[rdr][cdc],blenght });
						break;
					}
					else
						blenght++;

					rdr += dr[d];
					cdc += dc[d];
				}
			}
		}

	}

	int result = 0;
	while (!EdgeInfo.empty())
	{
		Edge node = EdgeInfo.top();
		EdgeInfo.pop();

		if (FIND(node.s) == FIND(node.e)) continue;

		UNION(node.s, node.e);
		result += node.w;
	}

	for (int i = 2; i < u.size(); i++)
	{
		if (FIND(i) != FIND(i - 1))
		{
			result = -1;
			break;
		}
	}

	cout << result << "\n";
}