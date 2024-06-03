#include <iostream>
using namespace std;
int N;
int Box[1002];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;

	int temp;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		Box[temp] = Box[temp - 1] + 1;
		for (int j = temp + 1; j <= 1000; j++)
			if (Box[j] < Box[temp])Box[j] = Box[temp];
	}
	cout << Box[1000] << '\n';
}