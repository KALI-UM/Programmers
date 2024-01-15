#include <iostream>
#include <vector>
using namespace std;

int N;
long long K;
const int mod = 1000;
vector<vector<int>> U;

vector<vector<int>>* multyply_Matrix(vector<vector<int>>& Matrix1, vector<vector<int>>& Matrix2)
{
	vector<vector<int>>* answer = new vector<vector<int>>(N,vector<int>(N,0));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int n = 0; n < N; n++)
			{
				(*answer)[i][j] += (Matrix1[i][n] * Matrix2[n][j])%1000;
				(*answer)[i][j] %= 1000;
			}
		}
	}

	return answer;
}

vector<vector<int>>* Pow(vector<vector<int>>& base, long long n)
{
	if (n == 0)return &U;
	if (n % 2 == 1)return (multyply_Matrix(*Pow(base, n - 1), base));
	else
	{
		vector<vector<int>>* half = Pow(base, n / 2);
		return multyply_Matrix(*half, *half);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	vector<vector<int>> Matrix(N, vector<int>(N, 0));
	U = vector<vector<int>>(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> Matrix[i][j];
			if (i == j)
				U[i][j] = 1;
		}
	}


	vector<vector<int>>* answer = Pow(Matrix, K);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout<< (*answer)[i][j]<<' ';

		cout << "\n";
	}

}