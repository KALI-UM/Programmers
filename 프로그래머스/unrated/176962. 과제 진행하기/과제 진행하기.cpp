#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
bool comp(vector<string>& a, vector<string>& b)
{
    for(int i=0; i<5; i++)
    {
        if(a[1][i]!=b[1][i])
        {
            return a[1][i]<b[1][i];
        }
    }
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    
    sort(plans.begin(), plans.end(), comp);
    
    vector<int> waiting;
    int prevtime=stoi(plans[0][1].substr(0,2))*60+stoi(plans[0][1].substr(3,2)) +stoi(plans[0][2]);;
    for(int i=1; i<plans.size(); i++)
    {
        int start = stoi(plans[i][1].substr(0,2))*60+stoi(plans[i][1].substr(3,2));
        int playtime = stoi(plans[i][2]);
          
        int temp = prevtime - start;         
        waiting.push_back(temp);
        
        if(temp<=0)
        {
            answer.push_back(plans[i-1][0]); 
        }
        
        if(temp<0)
        {
            for(int k=waiting.size()-1; k>=0; k--)
            {
                if(waiting[k]>0)
                {
                    waiting[k]=waiting[k]+temp;
                    temp =waiting[k];
                    
                    if(waiting[k]<=0)
                    {
                        answer.push_back(plans[k][0]);
                    }
                    if(temp>=0)
                    {
                        break;
                    }
                }
            }
        }

        prevtime=start+playtime;
    }
     
    answer.push_back(plans[plans.size()-1][0]);
    for(int j=waiting.size()-1; j>=0; j--)
    {
        if(waiting[j]>0)
        {
            answer.push_back(plans[j][0]);
        }
    }
    
    return answer;
}