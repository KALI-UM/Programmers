#include <iostream>
#include <algorithm>

using namespace std;
int N, K;
int Max = 0;
int AB[1000002];
int A = 0, B = 0;
pair<int, int> Line[1000];

bool WindowA(int b, int min, int max)
{
	int ABb = AB[b];
	if (ABb < K)return false;
	else if (ABb == K) 
	{
		A = 0;
		B = b;
		return true;
	}
	int ABa = ABb - K;
	
	while (min < max)
	{
		int mid = (min + max) / 2;
		if (AB[mid] > ABa)
			max = mid - 1;
		else if (AB[mid] < ABa)
			min = mid + 1;
		else
		{
			A = mid;
			B = b;
			return true;
		}
	}

	for (int a = max; a <= min; a++)
	{
		if (AB[a] == ABa)
		{
			A = a;
			B = b;
			return true;
		}
	}
	return false;
}

void FindAB()
{
	for (int ab = Line[0].first; ab <= Line[N - 1].second + 1; ab++)
	{
		AB[ab] = AB[ab - 1];
		for (int j = 0; j < N; j++)
		{
			if (ab <= Line[j].first)break;
			if (ab <= Line[j].second)
				AB[ab]++;
		}

		if (WindowA(ab, 0, ab - 1))
			return;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		cin >> Line[i].first >> Line[i].second;
		Max += Line[i].second - Line[i].first;
	}
	sort(&Line[0], &Line[N]);

	FindAB();
	cout << A << ' ' << B << '\n';
}

