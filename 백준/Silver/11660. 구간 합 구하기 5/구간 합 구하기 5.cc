#include <iostream>
#include <vector>
int N, M;
int numbers[1025][1025];
int sum[1025][1025];

using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> numbers[i][j];
			sum[i][j] = sum[i][j - 1] + sum[i-1][j]+numbers[i][j]-sum[i-1][j-1];
		}
	}

	int x1, y1, x2, y2;
	for (int i = 0; i < M; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		cout << sum[x2][y2] +sum[x1-1][y1-1]-sum[x1-1][y2]-sum[x2][y1-1]<< '\n';
	}

}
