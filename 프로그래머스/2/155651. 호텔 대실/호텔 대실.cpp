#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct comp
{
    
bool operator()(pair<int,int>& a, pair<int,int>& b)
{
    return a.first>b.first;
}
};

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, comp> startq;
    priority_queue<int, vector<int>, greater<int>> endq;
    
    for(auto& curr : book_time)
    {
        int start = stoi(curr[0].substr(0,2))*60+stoi(curr[0].substr(3,2));
        int end = stoi(curr[1].substr(0,2))*60+stoi(curr[1].substr(3,2));
        
        startq.push({start, end});
    }
     
    while(!startq.empty())
    {
        int s = startq.top().first;
        int e = startq.top().second+10;
        startq.pop();
       
        while(!endq.empty()&&s>=endq.top())
        {
            endq.pop();
        }
        
        endq.push(e);
        answer=max(answer, (int)endq.size());
    }
    
    return answer;
}