#include <iostream>
#include <string>
using namespace std;

void  inline Check(const char& a, const char& b, const char& c, int win[])
{
	if (a == b && b == c && a != '.')
		a == 'X' ? win[0]++ : win[1]++;
}

bool CheckTickTakToe(string str)
{
	int Xcnt = 0;
	int Ocnt = 0;
	for (int i = 0; i < 9; i++)
	{
		if (str[i] == 'X')Xcnt++;
		if (str[i] == 'O')Ocnt++;
	}
	if ((Xcnt - Ocnt != 1 && Xcnt - Ocnt != 0) || Xcnt < 3)return false;

	int win[2] = { 0,0 };
	Check(str[0], str[1], str[2], win);
	Check(str[3], str[4], str[5], win);
	Check(str[6], str[7], str[8], win);
	Check(str[0], str[3], str[6], win);
	Check(str[1], str[4], str[7], win);
	Check(str[2], str[5], str[8], win);
	Check(str[0], str[4], str[8], win);
	Check(str[2], str[4], str[6], win);

	if (win[0] != 0 && win[1] != 0)return false;
	else if (win[0] == 0 && win[1] == 0)return (Xcnt == 5 && Ocnt == 4);
	else if (win[0] != 0)return(Xcnt == Ocnt + 1);
	else if (win[1] != 0)return (Xcnt == Ocnt);
	else return false;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string temp;
	cin >> temp;
	while (temp != "end")
	{
		CheckTickTakToe(temp) ? cout << "valid\n" : cout << "invalid\n";
		cin >> temp;
	}
}