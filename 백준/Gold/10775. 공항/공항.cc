#include <iostream>
using namespace std;
int G, P;
int Group[100001];
int C = 0;
int Find(int index)
{
	if (Group[index] == index)return index;
	else return Group[index] = Find(Group[index]);
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);

	if (a > b)swap(a, b);
	Group[b] = a;
}

bool Push(int temp)
{
	int index = Find(temp);
	if (index == 0)return false;

	Union(temp, index-1);
	C++;
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> G >> P;

	for (int i = 0; i <= G; i++)
		Group[i] = i;

	int temp;
	for (int i = 0; i < P; i++)
	{
		cin >> temp;
		if (Push(temp) == false)
			break;
	}
	cout << C << '\n';
}