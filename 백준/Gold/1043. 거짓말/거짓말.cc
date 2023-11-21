#include <iostream>
#include <vector>
using namespace std;
vector<int> PersonList;
int Find(int node)
{
	if (PersonList[node] == node)return node;
	else
		return PersonList[node] = Find(PersonList[node]);
}

void Union(int node1, int node2)
{
	node1 = Find(node1);
	node2 = Find(node2);

	if (node1 > node2)
		swap(node1, node2);

	if (node1 == node2)return;

	PersonList[node2] = node1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int result = 0;

	int PersonCnt, PartyCnt;
	cin >> PersonCnt >> PartyCnt;
	PersonList = vector<int>(PersonCnt + 1);
	for (int i = 0; i <= PersonCnt; i++)
		PersonList[i] = i;
	int PersonCnt_true;
	cin >> PersonCnt_true;
	int index;
	for (int i = 0; i < PersonCnt_true; i++)
	{
		cin >> index;
		PersonList[index] = 0;
	}

	vector<int>Party(PartyCnt);
	int p, p1, p2;
	for (int i = 0; i < PartyCnt; i++)
	{
		cin >> p;

		cin >> p1;
		if (p != 1)
		{
			for (int j = 1; j < p; j++)
			{
				cin >> p2;
				Union(p1, p2);
				p1 = p2;
			}
		}
		Party[i] = Find(p1);
	}

	for (int i = 0; i < PartyCnt; i++)
		if (Find(Party[i]) != 0)result++;

	cout << result << "\n";
}