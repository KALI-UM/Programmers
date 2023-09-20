#include <iostream>
#include <vector>

using namespace std;
static vector<int> buffer;
static vector<int> v;
void Msort(int size, int index)
{
	int half = size / 2;
	if (size == 1)
	{
		return;
	}
	else if (size == 2)
	{
		if (v[index] > v[index + 1])
			swap(v[index], v[index+1]);

		return;
	}
	else
	{
		Msort(half, index);
		Msort(size - half, index + half);
	}
		
	int index1 = index;
	int index2 = half + index;
	int end1 = half + index;
	int end2 = index + size;
	int j = index;

	while (index1 < end1 && index2 < end2)
	{
		v[index1] < v[index2] ?
			buffer[j++] = v[index1++] : buffer[j++] = v[index2++];
	}
	
	while (index1 < end1)
	{
		buffer[j++] = v[index1++];
	}

	while (index2 < end2)
	{
		buffer[j++] = v[index2++];
	}

	for (int i = index; i < index + size; i++)
		v[i] = buffer[i];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	v=vector<int>(N,0);
	buffer = vector<int>(N, 0);
	for (int i = 0; i < N; i++)
	    cin >> v[i];

	Msort(v.size(), 0);
    
	for (int& number : v)
	{
		cout << number << "\n";
	}
}