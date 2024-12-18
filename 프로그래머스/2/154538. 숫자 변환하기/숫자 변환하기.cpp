#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int x, int y, int n) {
    int answer = -1;
    vector<bool> visited(y*3+1);
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    q.push({0,x});
    while(!q.empty())
    {
        int cnt=q.top().first;
        int value = q.top().second;
        q.pop();

        if(visited[value])
            continue;
   
        visited[value]=true;
        if(value==y)
        {
            answer=cnt;
            break;
        }
        
        int a = value+n;
        if(!visited[a]&&a<=y)
        {
            q.push({cnt+1, a});
        }
        int b = value*2;
        if(!visited[b]&&b<=y)
        {
            q.push({cnt+1, b});
        }
        int c = value*3;
        if(!visited[c]&&c<=y)
        {
            q.push({cnt+1, c});
        }
    }
    
    return answer;
}