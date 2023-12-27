#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

long CCW(long x1, long y1, long& x2, long& y2, long& x3, long& y3)
{
	return (x1 * y2 + x2 * y3 + x3 * y1) - (x1 * y3 + x2 * y1 + x3 * y2);
}

struct P
{
	long x, y;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	double result = 0;
	vector<P> p(N);
	for (int i = 0; i < N; i++)
	{
		cin >> p[i].x >> p[i].y;
	
		if (i >= 1)
			result += (double)CCW(0, 0, p[i - 1].x, p[i - 1].y, p[i].x, p[i].y);
	}
	result+= (double)CCW(0, 0, p[N-1].x, p[N - 1].y, p[0].x, p[0].y);

	cout<<fixed;
	cout.precision(1);
	cout << abs(result)/2 << "\n";
}