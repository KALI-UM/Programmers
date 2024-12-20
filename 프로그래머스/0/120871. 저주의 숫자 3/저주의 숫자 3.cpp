#include <string>
#include <vector>

using namespace std;

int GetNext3XNumber(int prev)
{
    int next = prev+1;
    while(true)
    {
        if(next%3==0)
            next++;
        else if(next%10==3)
            next++;
        else if((next%100)/10==3)
            next++;
        else if((next%1000)/100==3)
            next++;
            else 
                break;
    }
    return next;
}

int solution(int n) {
       int answer = 0;
    for(int i=1; i<=n; i++)
    {
        answer = GetNext3XNumber(answer);
    }
    return answer;
}