#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

vector<tuple<int, int, int>> recipe[10];
bool visited[10] = {false,};
long result[10];
long lcm = 1;

long gcd(long a, long b)
{
	//if (a < b)swap(a, b);

	if (b==0)
		return a;
	else
		return gcd(b, a % b);
}
void DFS(int node)
{
	visited[node] = true;
	for(tuple<int, int, int>& i: recipe[node])
	{
		int next = get<0>(i);
		if (visited[next] == false)
		{
			result[next] = result[node] * get<2>(i) / get<1>(i);
			DFS(next);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int a, b, p, q;
	for (int i = 1; i < N; i++)
	{
		cin >> a >> b >> p >> q;
		recipe[a].push_back(make_tuple(b, p, q));
		recipe[b].push_back(make_tuple(a, q, p));

		lcm *= p * q / gcd(p, q);
	}

	result[0] = lcm;
	DFS(0);

	long mgcd = result[0];
	for (int i = 1; i < N; i++)
		mgcd = gcd(mgcd, result[i]);

	for (int i = 0; i < N; i++)
		cout << result[i] / mgcd << ' ';

}