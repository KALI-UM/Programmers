#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
string result;
void getText(int a, int b, string& A, string& B, vector<vector<int>>& DP)
{
	if (a == 0 || b == 0) return;

	if (A[a] == B[b])
	{
		getText(a - 1, b - 1, A, B, DP);
		result += A[a];
	}
	else
	{
		if (DP[a - 1][b] > DP[a][b - 1])
			getText(a - 1, b, A, B, DP);
		else
			getText(a, b - 1, A, B, DP);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string A, B;
	cin >> A >> B;

	A = 'a' + A;
	B = 'b' + B;


	vector<vector<int>> DP(A.size(), vector<int>(B.size(), 0));
	for (int a = 1; a < A.size(); a++)
	{
		for (int b = 1; b < B.size(); b++)
		{
			if (A[a] == B[b])
			{
				DP[a][b] = DP[a - 1][b - 1] + 1;
			}
			else
				DP[a][b] = max(DP[a][b - 1], DP[a - 1][b]);
		}
	}

	cout << DP[A.size() - 1][B.size() - 1] << "\n";
	getText(A.size() - 1, B.size() - 1, A, B, DP);
	cout << result << "\n";
}