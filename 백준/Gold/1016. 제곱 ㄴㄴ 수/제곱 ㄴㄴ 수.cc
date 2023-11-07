#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	//bad alloc뜸
	//long Min, Max;
	//cin >> Min >> Max;
	//long result = Max - Min + 1;
	//vector<bool> numbers(Max + 1, true);
	//for (long i = 2; i < (long)ceil(sqrt((double)(Max + 1))); i++)
	//{
	//	long temp = i * i;
	//	if (numbers[temp] == true)
	//	{
	//		for (long j = 1; j < (long)ceil((double)(Max + 1) / (double)temp); j++)
	//		{
	//			if (temp * j >= Min && numbers[temp * j] == true)
	//				result--;

	//			numbers[temp * j] = false;
	//		}
	//	}
	//}
	//cout << result << "\n";


	long Min, Max;
	cin >> Min >> Max;
	long result = Max - Min + 1;
	vector<bool> numbers(Max - Min+1, true);
	for (long i = 2; i < (long)ceil(sqrt((double)(Max + 1))); i++)
	{
		long temp = i * i;
		for (long j = (long)ceil((double)Min / (double)temp); j < (long)ceil((double)(Max + 1) / (double)temp); j++)
		{
			if (temp * j >= Min && numbers[temp * j - Min] == true)
				result--;

			numbers[temp * j - Min] = false;
		}
	}
	cout << result << "\n";
}