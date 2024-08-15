#include <string>
#include <vector>
#include <queue>

using namespace std;

bool CanSwitch(string& a, string& b)
{
    bool diff=false;
    for(int i=0; i<a.length(); i++)
    {
        if(a[i]!=b[i])
        {
            if(diff==true)return false;
            diff=true;
        } 
    }
    return true;
}

int BFS(string& begin, string& target, vector<string>& words)
{
    queue<int> q1;
    queue<int> q2;
    
    queue<int>* nowq=&q1;
    queue<int>* nextq=&q2;
    
    int result=1;
    int targetIndex=-1;
    for(int i=0; i<words.size();i++)
    {
        if(CanSwitch(begin, words[i]))
            nowq->push(i);
        
        if(target.compare(words[i])==0)
            targetIndex=i;
    }
    int cnt=1;
    if(targetIndex==-1)return 0;
    
    vector<bool> visited(words.size(), false);
    vector<vector<bool>> words_canswitch(words.size(), vector<bool>(words.size(),false));
    for(int i=0; i<words.size(); i++)
    {
        for(int j=0; j<=i; j++)
        {
            if(i==j)words_canswitch[i][j]=false;
            else
            {
                words_canswitch[i][j]=CanSwitch(words[i], words[j]);
                words_canswitch[j][i]=words_canswitch[i][j];
            }
        }
    }
    
    while(!nowq->empty())
    {
        int nowstr=nowq->front();
        nowq->pop();
        
        if(nowstr==targetIndex)
            return cnt;
        
        if(visited[nowstr]==false)
        {
            visited[nowstr]=true;
            
            for(int i=0; i<words.size(); i++)
            {
                if(words_canswitch[nowstr][i]&&!visited[i])
                    nextq->push(i);
            }
        }
         
        if(nowq->empty()&&!nextq->empty())
        {
            cnt++;
            swap(nowq, nextq);
        } 
    }
    return 0;
}


int solution(string begin, string target, vector<string> words) {
    int answer = BFS(begin, target, words);
    return answer;
}