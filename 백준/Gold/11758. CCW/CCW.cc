#include <iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int x1, y1;
	int x2, y2;
	int x3, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	
	int result = (x1 * y2 + x2 * y3 + x3 * y1) - (x1 * y3 + x2 * y1 + x3 * y2);
	if (result > 0) result = 1;
	else if (result < 0)result = -1;
	cout << result << "\n";
}