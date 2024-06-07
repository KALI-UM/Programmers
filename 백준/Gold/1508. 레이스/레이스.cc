#include <iostream>
using namespace std;
int N, M, K;
int Kpoint[50];

bool IsPossible(int distance)
{
	int prev = Kpoint[0];
	int cnt = 1;
	for (int i = 1; i < K; i++)
	{
		if (Kpoint[i] - prev >= distance)
		{
			prev = Kpoint[i];
			cnt++;
			if (cnt == M)return true;
		}
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> K;
	for (int k = 0; k < K; k++)
		cin >> Kpoint[k];

	int distance = Kpoint[K - 1] - Kpoint[0];
	while (!IsPossible(distance))
	{
		distance /= 2;
	}
	while (IsPossible(distance))
	{
		distance++;
	}
	distance--;

	cout << 1;
	int prev = Kpoint[0];
	int cnt = 1;
	for (int i = 1; i < K; i++)
	{
		if (cnt != M && Kpoint[i] - prev >= distance)
		{
			cout << 1;
			prev = Kpoint[i];
			cnt++;
		}
		else
			cout << 0;
	}
	cout << '\n';
}