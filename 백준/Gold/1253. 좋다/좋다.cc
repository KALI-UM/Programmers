#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin>>N;
    
    vector<int> list(N,0);
    for(int i=0; i<N; i++)
        cin>>list[i];
    sort(list.begin(), list.end());
    
    int answer =0;
    
    for(int i=0; i<N; i++)
    {
        int start = 0;
        int end = N-1;
        while(start<end)
        {
            if((list[start]+list[end])==list[i])
            { 
                if(start!=i&&end!=i)
                {
                     answer++;
                   break;
                }
                else if(start==i)
                {
                    start++;
                }
                else if(end==i)
                {
                    end--;
                }

            }
            else if((list[start]+list[end])>list[i])
                end--;
            else if((list[start]+list[end])<list[i])
                start++;
        }
    }

    cout<<answer;
    
}