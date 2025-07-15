#include <iostream>
#include <vector>
int N,M;

using namespace std;
int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >>N>>M;
	vector<int> numbers(N+1);
	vector<int> sum(N+1);
	for (int i = 1; i <= N; i++)
	{
		cin >> numbers[i];
		sum[i] = sum[i - 1] + numbers[i];
	}


	int s, e;
	for (int i =0; i < M; i++)
	{
		cin >> s >> e;
		cout << sum[e] - sum[s-1]<<'\n';
	}

}
