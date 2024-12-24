#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool comp(const vector<int>& a, const vector<int>& b)
{
    return a[1]<b[1];
}

int solution(vector<vector<int>> targets) {
    int answer = 0;
    
    sort(targets.begin(), targets.end(), comp);
    
    int tar=-1;
    for(auto& k : targets)
    {
        if(k[0]>=tar)
        {
            tar=k[1];
           answer++;
        }
    }
    
 
    
    return answer;
}