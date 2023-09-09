#include <string>
#include <vector>
#include <algorithm>
//#include <iostream>

using namespace std;

bool comp(vector<int>& a, vector<int>& b)
{
    return a[0]==b[0]? (a[1]==b[1]? a[2]>b[2] :a[1]>b[1]) :a[0]>b[0];
}

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;

    int min = (picks[0]+picks[1]+picks[2])*5 <minerals.size()? (picks[0]+picks[1]+picks[2])*5 : minerals.size();
    vector<vector<int>> mineralcnt;
    for(int i=0; i<min; i++)
    {
        if(i%5==0)
        {
            mineralcnt.push_back({0,0,0});
        }
        
        if(minerals[i][0]=='d')
        {
            mineralcnt[i/5][0]+=1;
        }
        else if(minerals[i][0]=='i')
        {
            mineralcnt[i/5][1]+=1;
        }      
        else
        {
            mineralcnt[i/5][2]+=1;     
        }
    }
    
    sort(mineralcnt.begin(), mineralcnt.end(), comp);
    
    for(auto& k : mineralcnt)
    {
        //cout<<k[0]<<k[1]<<k[2]<<endl;

       if(picks[0]!=0)
       {
            answer+=k[0]+k[1]+k[2];
            picks[0]-=1; 
       }
        else if(picks[1]!=0)
        {
            answer+=k[0]*5+k[1]+k[2];
            picks[1]-=1; 
        }
        else if(picks[2]!=0)
        {
            answer+=k[0]*25+k[1]*5+k[2];
            picks[2]-=1; 
        }
        else
        {
            break;
        }
    }
    
    return answer;
}