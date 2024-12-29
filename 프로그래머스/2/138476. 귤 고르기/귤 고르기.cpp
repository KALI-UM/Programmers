#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    vector<int> tangerine_size(10000001);
    
    for(int i=0; i<tangerine.size(); i++)
    {
        tangerine_size[tangerine[i]-1]++;
    }

    sort(tangerine_size.begin(), tangerine_size.end(), [](int x, int y){return x>y;});
    
    for(int i=0; i<tangerine.size(); i++)
    {
        k-=tangerine_size[i];
        if(k<=0)
        {
            answer=i+1;
            break;
        }
    }
        
    return answer;
}