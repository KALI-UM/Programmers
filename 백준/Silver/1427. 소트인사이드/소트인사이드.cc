#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> v;
	while (N!=0)
	{
		v.push_back(N%10);
		N = N / 10;
	}

	for (int i = 0; i < v.size()-1; i++)
	{
		int max = i;
		for (int j = i; j < v.size(); j++)
		{
			v[j] > v[max] ? max = j : max = max;
		}
		int temp = v[i];
		v[i] = v[max];
		v[max] = temp;
		cout << v[i];
	}
	cout << v.back();
}