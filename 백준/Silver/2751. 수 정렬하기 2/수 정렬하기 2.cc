#include <iostream>
#include <vector>

using namespace std;
static vector<int> buffer;
static vector<int> v;

void Msort(int s, int e)
{
	if (e - s < 1)
		return;

	int m = s + (e - s) / 2;

	Msort(s, m);
	Msort(m+1, e);

	for (int i = s; i <= e; i++)
		buffer[i] = v[i];

	int k = s;
	int index1 = s;
	int index2 = m + 1;

	while (index1 <= m && index2 <= e)
	{
		if (buffer[index1] < buffer[index2])
		{
			v[k] = buffer[index1];
			index1++;
			k++;
		}
		else
		{
			v[k] = buffer[index2];
			index2++;
			k++;
		}
	}

	while (index1 <= m)
	{
		v[k] = buffer[index1];
		index1++;
		k++;
	}

	while (index2 <= e)
	{
		v[k] = buffer[index2];
		index2++;
		k++;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	v=vector<int>(N+1,0);
	buffer = vector<int>(N+1, 0);
	for (int i = 1; i <= N; i++)
	{
		cin >> v[i];
	}

	Msort(1, N);
	for (int i=1; i<=N;i++)
	{
		cout << v[i] << "\n";
	}
}