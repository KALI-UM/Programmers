#include <iostream>
using namespace std;

class Node
{
public:
	Node* next[26];
	bool isEnd;
	Node()
		: isEnd(false)
	{
		fill(next, next + 26, nullptr);
	}

	~Node()
	{
		for (auto& child : next)
			delete child;
	}

	void Insert(const char* key)
	{
		if (*key == 0)
		{
			isEnd = true;
		}
		else
		{
			int nextIndex = *key - 'a';
			if (next[nextIndex] == nullptr)
				next[nextIndex] = new Node();

			next[nextIndex]->Insert(key + 1);
		}
	}

	Node* Find(const char* key)
	{
		if (*key == 0)
		{
			return this;
		}

		int nextIndex = *key - 'a';

		if (next[nextIndex] == nullptr)
		{
			return nullptr;
		}
		else
			return next[nextIndex]->Find(key + 1);
	}

};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	Node* root = new Node();
	for (int i = 0; i < N; i++)
	{
		char temp[501];
		cin >> temp;
		root->Insert(temp);
	}

	int result = 0;
	for (int i = 0; i < M; i++)
	{
		char temp[501];
		cin >> temp;
		Node* n=root->Find(temp);

		if (n != nullptr && n->isEnd == true)result++;
	}

	cout << result << "\n";


}