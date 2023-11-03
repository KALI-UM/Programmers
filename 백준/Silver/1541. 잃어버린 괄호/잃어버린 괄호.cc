#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int result=0;
	string formula;

	cin >> formula;
	formula = '+' + formula;
	vector<int> numbers;

	int prevoperatorindex = (int)formula.length();
	int number = 0;
	int temp = 0;
	for (int i = formula.length() - 1; i >= 0; i--)
	{
		if (formula[i] == '-')
		{
			number = stoi(formula.substr(i+1, prevoperatorindex-i-1));
			temp += number;
			result -= temp;
			temp = 0;
			prevoperatorindex = i;
		}
		else if (formula[i] == '+')
		{
			number = stoi(formula.substr(i+1, prevoperatorindex-i-1));
			temp += number;
			prevoperatorindex = i;
		}
	}

	result += temp;
	cout << result << "\n";
}