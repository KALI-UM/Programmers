#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<int> v(N,0);
	int maxIndex = N - 1;
	int result = 0;
	for (int i = 0; i < N; i++)
		cin >> v[i];
	
	while(M>0)
	{
		if (M>=v[maxIndex])
		{
			result += M / v[maxIndex];
			M = M % v[maxIndex];
		}
		maxIndex--;
	}
	cout << result<<"\n";
}  