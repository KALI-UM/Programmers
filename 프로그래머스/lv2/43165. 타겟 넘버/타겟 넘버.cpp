#include <string>
#include <vector>

using namespace std;


int cnt=0;
void dfs(int sum, int index, vector<int>& numbers, int target)
{
   
    if(numbers.size()==index)
    {
        if(sum==target)
        {
            cnt++;
        }
        
        return;
    }

    dfs(sum+numbers[index],index+1, numbers, target);
    dfs(sum-numbers[index],index+1, numbers, target);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    dfs(0,0, numbers, target);
    answer = cnt;
    return answer;
}