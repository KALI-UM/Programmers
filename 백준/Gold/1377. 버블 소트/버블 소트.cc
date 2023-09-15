#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int a = -1 * N;
	vector <pair<int, int>> v;
	for (int i = 0; i < N; i++)
	{
		int number;
		cin >> number;	
		v.push_back(make_pair(number, i));
	}
	sort(v.begin(), v.end());

	for (int i=0; i<N; i++)
	{
		v[i].second - i > a ? a = v[i].second - i : a = a;
	}
		cout <<++a;
}