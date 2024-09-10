#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int weight[30];
int target[7];
int max_weight=0;
bool weight_possible[40001] = { false, };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> weight[i];
		max_weight += weight[i];
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> target[i];
	}

	weight_possible[0] = true;
	for (int i = 0; i <N; i++)
	{
		for (int w = max_weight; w >= 0; w--)
			if (weight_possible[w])
				weight_possible[w + weight[i]]=true;
		for (int w = 0; w <= max_weight; w++)
			if (weight_possible[w])
				weight_possible[abs(w - weight[i])] = true;
	}

	for (int i = 0; i < M; i++)
	{
		weight_possible[target[i]] ? cout << "Y " : cout << "N ";
	}
}

