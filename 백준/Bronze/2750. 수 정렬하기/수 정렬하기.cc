#include <iostream>
#include <vector>

using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> v(N,0);
	for (int i = 0; i < N; i++)
	{
		int number;
		cin >> number;
		
		v[i] = number;
	}

	bool done = false;
	while (!done)
	{
		done = true;
		for (int i = 0; i < N-1; i++)
		{
			if (v[i] > v[i + 1])
			{
				int temp = v[i];
				v[i] = v[i + 1];
				v[i + 1] = temp;

				done = false;
			}
		}
	}

	for (int& num : v)
	{
		cout << num << endl;
	}
}