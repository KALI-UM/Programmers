#include <string>
#include <vector>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    
    vector<vector<int>> weightMap(1001);
    for(int i=0; i<weights.size(); i++)
    {
        weightMap[weights[i]].push_back(i);
    }
    
    for(int i=100; i<weightMap.size(); i++)
    {
        if(weightMap[i].size()==0)
            continue;
        
        long long temp = 0;
        
        answer+=weightMap[i].size()*(weightMap[i].size()-1)/2;
        
        if(i*2<weightMap.size())
        {
            temp+=weightMap[i*2].size();    
        }
        if(i%2==0&&(i/2*3)<weightMap.size())
        {
            temp+=weightMap[i/2*3].size();
        }
        if(i%3==0&&(i/3*4)<weightMap.size())
        {
            temp+=weightMap[i/3*4].size();   
        }
        
        answer+=temp*weightMap[i].size();
    }
    
    return answer;
}