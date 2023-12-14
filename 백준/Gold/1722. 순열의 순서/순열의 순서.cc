#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int A, B;
long C;
vector<int> number;
long factorial(long k)
{
	long result = 1;
	while (k >= 1)
		result *= k--;
	return result;
}

void Q1(long k)
{
	k--;
	while (A > 0)
	{
		long i;
		if (k == 0)i = 0;
		else i = k / factorial(A - 1);

		k=k% factorial(A - 1);
		cout<<number[i]<<' ';
		number.erase(number.begin() + i);
		A--;
	}
	cout <<  "\n";
}

void Q2()
{
	long result = 1;
	long temp;
	for (int a = 0; a < A; a++)
	{
		cin >> temp;
		long i = find(number.begin(), number.end(), temp) - number.begin();
		result += i* factorial(A - a-1);
		number.erase(number.begin() + i);
	}
	cout << result << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> A >> B;
	number.resize(A);
	for (int i = 0; i < A; i++)
		number[i] = i+1;

	if (B == 1)
	{
		cin >> C;
		Q1(C);
	}
	else
		Q2();

}