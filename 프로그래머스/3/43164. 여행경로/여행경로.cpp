#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;
map<string, int> Airport2Index;

int str2Index(string str)
{
    if(Airport2Index.find(str)==Airport2Index.end())return -1;
    return Airport2Index[str];
}

bool DFS(int curr, vector<string>& answer, vector<vector<int>>& t, vector<vector<string>>& tickets, vector<bool>& v)
{      
    bool done=true;

  for(int i=0; i<v.size(); i++)
  {
      if(v[i]==false)
      {
          done=false;
          break;
      }
  }
    if(done)return true;
    if(curr==-1)return false;
    
    for(int i=0; i<t[curr].size(); i++)
    {
        int tnum=t[curr][i];
        if(v[tnum]==false)
        {
            answer.push_back(tickets[tnum][1]);
            v[tnum]=true;
            int next= str2Index(tickets[tnum][1]);
            if(DFS(next,answer,t,tickets,v))
                return true;
            else
            {
                answer.pop_back();
                v[tnum]=false;
            }
        } 
    }
   return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    answer.push_back("ICN");
    sort(tickets.begin(), tickets.end());
  
    int AirportIndex=0;
    int ICN;
    for(int i=0; i<tickets.size(); i++)
    {
        if(Airport2Index.find(tickets[i][0])==Airport2Index.end())
        {
           // cout<<tickets[i][0]<<", " <<AirportIndex<<'\n';
            if(tickets[i][0].compare("ICN")==0)
                ICN=AirportIndex;
            Airport2Index.emplace(tickets[i][0],AirportIndex++);
        }      
    }
    vector<vector<int>> tickets_(Airport2Index.size(), vector<int>()); 
    vector<bool> tickets_visited(tickets.size(),false);
    for(int i=0; i<tickets.size(); i++)
    {
        tickets_[str2Index(tickets[i][0])].push_back(i);
    }
    DFS(ICN, answer, tickets_, tickets, tickets_visited);
    
    // for(int i=0; i<answer.size(); i++)
    //     cout<<answer[i]<<'\n';
    
    return answer;
}