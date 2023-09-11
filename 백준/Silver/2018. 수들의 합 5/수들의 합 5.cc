#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int answer=0;
    
    int N; 
    cin>>N;
    
    int start=1;
    int end=1;
    
    int sum=1;
    
    while(start<=N/2)
    {
        if(sum<N)
        {
            end++;
            sum+=end;
        }
        else if(sum==N)
        {
            answer++;
            sum-=start;
            start++;
            end++;
            sum+=end;
        }
        else
        {
            sum-=start;
            start++;
        }
    }
    
    answer++;
    cout<<answer;
}