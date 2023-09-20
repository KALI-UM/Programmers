#include<iostream>
#include<stack>
#include<vector>

using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> LIST(N, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> LIST[i];
    }
    vector<char> answer;
    stack<int> list;
    int max = 1;

    for (int i = 0; i < N; i++)
    {
        while (LIST[i] >= max)
        {
            list.push(max++);
            answer.push_back('+');
        }

        if (list.top() == LIST[i])
        {
            list.pop();
            answer.push_back('-');
        }
        else
        {
            max = -1;
            cout << "NO";
            break;
        }
    }

    if (max != -1)
    {
        for (char& k : answer)
        {
            cout << k << "\n";
        }
    }

}