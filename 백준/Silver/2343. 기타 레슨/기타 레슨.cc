#include <iostream>
#include <vector>

using namespace std;
int Find(vector<int>& length, int brcnt, int min, int max)
{
	int start = min;
	int end = max;
	int mid;

	while (start < end)
	{
		mid = (start + end) / 2;
		vector<int> temp(brcnt + 2, 0);
		int cnt = 1;
		for (int i = 1; i < length.size(); i++)
		{
			if (length[i] - temp[cnt - 1] == mid && cnt < brcnt)
			{
				temp[cnt] = length[i];
				cnt++;
			}
			else if (length[i] - temp[cnt - 1] > mid)
			{
				temp[cnt] = length[i - 1];
				cnt++;
				if (cnt == brcnt+1)break;
			}
		}
		if (cnt == brcnt + 1)start = mid + 1;
		else if (cnt == brcnt)end--;
		else end = mid - 1;
	}
	return start;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M; //레슨 갯수, 블루레이 갯수
	cin >> N >> M;
	int time = 0;
	int maxTime = -1;
	vector<int> Length(N + 1);
	for (int i = 1; i <= N; i++)	//어차피 계속 더할 것이기 때문에 미리 더해본다 
	{
		cin >> time;
		Length[i] = Length[i - 1] + time;
		maxTime < time ? maxTime = time : maxTime;
	}
	cout << Find(Length, M, maxTime, Length[N]) << "\n";
}