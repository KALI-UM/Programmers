#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
	Node(Node* p, char n)
	{
		parent = p;
		name = n;
	}
	char name;
	Node* parent;
	Node* left = nullptr;
	Node* right = nullptr;
};

vector<Node*> list;

void Preorder(Node* curr)
{
	if (curr == nullptr)return;

	cout << curr->name;
	Preorder(curr->left);
	Preorder(curr->right);
}

void Inorder(Node* curr)
{
	if (curr == nullptr)return;

	Inorder(curr->left);
	cout << curr->name;
	Inorder(curr->right);
}

void Postorder(Node* curr)
{
	if (curr == nullptr)return;

	Postorder(curr->left);
	Postorder(curr->right);
	cout << curr->name;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	Node* root = new Node(nullptr, 'A');
	list.resize(26);
	list[0] = root;
	Node* curr = root;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		char temp[3];
		cin >> temp[0] >> temp[1] >> temp[2];

		curr = list[temp[0] - 'A'];
		if (temp[1] != '.')
		{
			curr->left = new Node(curr, temp[1]);
			list[temp[1] - 'A'] = curr->left;
		}
		if (temp[2] != '.')
		{
			curr->right = new Node(curr, temp[2]);
			list[temp[2] - 'A'] = curr->right;
		}
	}


	Preorder(root);
	cout << "\n";
	Inorder(root);
	cout << "\n";
	Postorder(root);
	cout << "\n";

}