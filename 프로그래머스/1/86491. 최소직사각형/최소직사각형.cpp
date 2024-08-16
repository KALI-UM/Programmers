#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    int width_max=0;
    int height_max=0;
    
    for(int i=0; i<sizes.size(); i++)
    {
        int w=max(sizes[i][0],sizes[i][1]);
        int h=min(sizes[i][0],sizes[i][1]);
        
        width_max=max(width_max,w);
        height_max=max(height_max,h);
    }
    answer=width_max*height_max;
    
    return answer;
}