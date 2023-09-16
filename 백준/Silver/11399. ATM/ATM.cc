#include <iostream>
#include <vector>
#include <list>

using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> v(N);
	list<int> l;
	int answer = 0;
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}

	l.push_back(v[0]);
	list<int>::iterator li = l.begin();
	for (int i = 1; i < N; i++)
	{
		li = l.begin();
		while (true)
		{
			if (li == l.end()||(*li) > v[i])
			{
				l.insert(li, v[i]);
				break;
			}
			else 
				li++;
		}
	}

	for (int& time : l)
	{
		sum += time;
		answer += sum;
	}
	cout << answer;
}