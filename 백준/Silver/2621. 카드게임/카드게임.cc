#include <iostream>
using namespace std;
#define R 0
#define G 1
#define B 2
#define Y 3

int Color[4];
int Number[10];

inline int Color2Index(const char& c)
{
	switch (c)
	{
	case 'R':
		return R;
	case 'G':
		return G;
	case 'B':
		return B;
	case 'Y':
		return Y;
	}
}

int Check()
{
	bool sameColor;
	int sequentialNumber = 0;
	int sameNumber[5] = { 0, };
	int maxNumber = 0;

	for (int i = 0; i < 4; i++)
	{
		sameColor = (Color[i] == 5);
		if (sameColor)break;
	}

	for (int i = 1; i <= 9; i++)
	{
		if (Number[i] != 0 && maxNumber < i)maxNumber = i;


		switch (Number[i])
		{
		case 1:
		{
			if (sequentialNumber == 0 || sequentialNumber + 1 == i)sequentialNumber = i;
			else
			{
				sequentialNumber = -1;
				sameNumber[0] = -1;
			}

			break;
		}
		case 2:
		{
			sameNumber[0] = -1;
			if (sameNumber[2] == 0)sameNumber[2] = i;
			else sameNumber[1] = i;
			break;
		}
		case 3:
		case 4:
		{
			sameNumber[0] = -1;
			sameNumber[Number[i]] = i;
			break;
		}
		}
	}

	if (sameColor && sequentialNumber != -1 && sequentialNumber != 0 && sameNumber[0] != -1)return 900 + sequentialNumber;
	if (sameNumber[4] != 0)return 800 + sameNumber[4];
	if (sameNumber[3] != 0 && sameNumber[2] != 0)return 700 + sameNumber[3] * 10 + sameNumber[2];
	if (sameColor)return 600 + maxNumber;
	if (sequentialNumber != -1 && sequentialNumber != 0 && sameNumber[0] != -1)return 500 + sequentialNumber;
	if (sameNumber[3] != 0)return 400 + sameNumber[3];
	if (sameNumber[2] != 0 && sameNumber[1] != 0)return 300 + sameNumber[1] * 10 + sameNumber[2];
	if (sameNumber[2] != 0)return 200 + sameNumber[2];
	else return 100 + maxNumber;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	char c; int n;
	for (int i = 0; i < 5; i++)
	{
		cin >> c >> n;
		Color[Color2Index(c)]++;
		Number[n]++;
	}

	cout << Check() << '\n';
}