#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int C, K;
	int dol = 0;
	cin >> C;
	vector<int>color(C);
	for (int i = 0; i < C; i++)
	{
		cin >> color[i];
		dol += color[i];
	}
	cin >> K;

	double result = 0;

	for (int i = 0; i < color.size(); i++)
	{
		if (color[i] < K) continue;
		int k = 0;
		double temp = 1;
		while (k < K)
		{
			temp = temp * (double)(color[i] - k) / (double)(dol - k);
			k++;
		}
		result += temp;
	}

	cout.precision(9);
	cout << result << "\n";

}