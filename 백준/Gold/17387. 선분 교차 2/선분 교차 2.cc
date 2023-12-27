#include <iostream>
#include <cmath>
using namespace std;

long CCW(long x1, long y1, long x2, long y2, long x3, long y3)
{
	long result = (x1 * y2 + x2 * y3 + x3 * y1) - (x1 * y3 + x2 * y1 + x3 * y2);
	if (result > 0)
		return 1;
	else if (result < 0)
		return -1;
	else
		return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long x1, y1;
	long x2, y2;
	long x3, y3;
	long x4, y4;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

	long result1 = CCW(x1, y1, x2, y2, x3, y3);
	long result2 = CCW(x1, y1, x2, y2, x4, y4);
	long result3 = CCW(x3, y3, x4, y4, x1, y1);
	long result4 = CCW(x3, y3, x4, y4, x2, y2);


	if (result1 * result2 == 0 && result3 * result4 == 0)
	{
		if (max(x1, x2) >= min(x3, x4) && max(y1, y2) >= min(y3, y4) && max(x3, x4) >= min(x1, x2) && max(y3, y4) >= min(y1, y2))
			cout << 1 << "\n";
		else
			cout << 0 << "\n";
	}
	else if (result1 * result2 <= 0 && result3 * result4 <= 0)
		cout << 1 << "\n";
	else
		cout << 0 << "\n";

}