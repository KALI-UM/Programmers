#include <string>
#include <vector>
#include <cmath>
#include <map>

using namespace std;
vector<int> sosu;
vector<map<int,int>> S; //<수, 방문비트
int D;
void SetSosu(int digit)
{
    for(int i=8; i<=pow(10, digit); i++)
    {
        for(int j=0; j<sosu.size(); j++)
        {
            if(i%sosu[j]==0)break;
            else if(i<sosu[j]*sosu[j])
            {
                sosu.push_back(i);
                break;
            }
        }
    }
}

bool IsSosu(int v)
{
    if(v==0||v==1)return false;
    for(int i=0; i<sosu.size(); i++)
    {
        if(v==sosu[i])return true;
        else if(v%sosu[i]==0)return false;
        else if(v<sosu[i]*sosu[i])return true;
    }
    return false;
}

void MakeNumber(string& number, int& answer, int digit)
{
    int d= pow(10, digit-1);
   map<int,int>::iterator it= S[digit-1].begin();
    for(; it!=S[digit-1].end(); it++)
    {
        for(int i=0; i<D; i++)
        {
             if((it->second&(1<<(i+1)))==0)
             {
                 int n=((int)(number[i])-(int)'0')*d+it->first;
                 if(S[digit].find(n)==S[digit].end())
                 {
                    S[digit].insert({n, it->second|(1<<(i+1))});
                     if(number[i]!='0'&&IsSosu(n))answer++;
                 }
             }
        }
       
    }
        
}

int solution(string numbers) {
    int answer = 0;
    sosu.push_back(2);
    sosu.push_back(3);
    sosu.push_back(5);
    sosu.push_back(7);
    D=numbers.length();
    S= vector<map<int,int>>(D+1, map<int,int>());
    SetSosu(D);
    for(int i=0; i<D; i++)
    {
        int v=(int)(numbers[i])-(int)'0';
        if(S[1].find(v)==S[1].end())
        { 
            S[1].insert({v,(0|(1<<(i+1)))});
            if(numbers[i]!='0'&&IsSosu(v))answer++;
        }
    }
 
    for(int i=2; i<=D; i++)
    {
      MakeNumber(numbers, answer, i);
    }
                        
                        
    return answer;
}