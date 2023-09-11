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
    int M;
    cin>>N;
    cin>>M;
    
    int answer=0;
    
    vector<int> list(N,0);
    
    for(int i=0; i<N; i++)
    {
        cin>>list[i];
    }
    
    sort(list.begin(),list.end());
    
    int start =0;
    int end =N-1;
    int sum=0;
    
    while(start<end)
    {
        sum=list[start]+list[end];
        if(sum>M)
        {
            end--;
        }
        else if(sum<M)
        {
            start++;
        }
        else
        {
            answer++;
            end--;
            start++;
        }
    }

    cout<<answer<<endl;
}