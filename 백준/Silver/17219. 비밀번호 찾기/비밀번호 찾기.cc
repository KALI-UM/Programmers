#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;
int N, M;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string site, pw;
	cin >> N >> M;
	unordered_map<string, string> SiteNPW;
	for (int i = 0; i < N; i++)
	{
		cin >> site >> pw;
		SiteNPW.emplace(site, pw);
	}

	for (int i = 0; i < M; i++)
	{
		cin >> site;
		cout << SiteNPW[site] << '\n';
	}
}

