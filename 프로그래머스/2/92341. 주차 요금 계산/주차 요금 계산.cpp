#include <string>
#include <vector>
#include <map>
#include <iostream>


using namespace std;

int ConvertStringToMin(string str)
{
    return stoi(str.substr(0,2))*60 +stoi(str.substr(3,2)); 
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    map<string,vector<int>> car;
    
    int max = 24*60-1;
    for(string& curr : records)
    {
        int min = ConvertStringToMin(curr);
        string carnum = curr.substr(6,4);
        bool isIn = curr.substr(11)=="IN";
        auto it = car.find(carnum);
        
        if(isIn)
        {
            if(it==car.end())
            {
                car.insert({carnum, vector<int>(1, max-min)});
            }
            else
            {
                it->second.push_back(max-min);
            }
        }
        else
        {
            it->second[it->second.size()-1]-=max-min;
        }
    }
    
    for(auto t : car)
    {
        int cost=fees[1];
        int time=0;
        for(auto tt : t.second)
        {
            time+=tt;
        }
        time-= fees[0];
        
        if(time>0)
        {      
            cost+=(time/fees[2])*fees[3];
            if(time%fees[2]!=0)
                cost+=fees[3];
        }
         answer.push_back(cost);
    }
    
    return answer;
}