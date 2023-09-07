#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    
    answer.push_back(0);
    answer.push_back(0);

    int temp=0;
    
    for(int i=sequence.size()-1; i>=0; i--)
    {
        if(sequence[i]>k)
        {
            continue;
        }
        else if(sequence[i]==k)
        {
           while(i>0&&sequence[i]==sequence[i-1])
           {
               i--;
           }
            
            answer[0]=i;
            answer[1]=i;
            
            break;
        }
        else
        {
            answer[temp==0? 1: 0]=i;
            temp+=sequence[i]; 

            if(temp==k)
           {        
                 while(i>0&&sequence[answer[0]-1]==sequence[answer[1]])
                {
                    i--;
                    answer[0]=i;
                    answer[1]=answer[1]-1;
                }
                break;
            }
            else if(temp>k)
            {
                temp-=sequence[answer[1]];
                answer[1]=answer[1]-1;
            }       
        }   
    }

    return answer;
}
