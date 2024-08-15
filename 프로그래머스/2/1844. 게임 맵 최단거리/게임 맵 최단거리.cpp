#include<vector>
#include<queue>
using namespace std;

int BFS(vector<vector<int>>& maps)
{
    queue<pair<int,int>> q1;
    queue<pair<int,int>> q2;
    q1.push({0,0});
    
    queue<pair<int,int>>* nowq=&q1;
    queue<pair<int,int>>* nextq=&q2;
    
    vector<vector<bool>> visited(maps.size(), vector<bool>(maps[0].size(),false));
    
    int cnt=0;
    int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    
    while(!nowq->empty())
    {
        int nowr=nowq->front().first;
        int nowc=nowq->front().second;
        nowq->pop(); 
        if(nowr==maps.size()-1&&nowc==maps[0].size()-1)
        {
            cnt++;
            return cnt;
        }
        
        if(visited[nowr][nowc]==false)
        { 
        visited[nowr][nowc]=true;
        
        for(int d=0; d<4; d++)
        {
            int nextr=nowr+dir[d][0];
            int nextc=nowc+dir[d][1];
            if(nextr>=0&&nextc>=0&&nextr<maps.size()&&nextc<maps[0].size()&&maps[nextr][nextc]==1&&visited[nextr][nextc]==false)
            {
                nextq->push({nextr, nextc});
            }
        }
        }
        if(nowq->empty()&&!nextq->empty())
        {
            cnt++;
            queue<pair<int,int>>* temp=nowq;
            nowq=nextq;
            nextq=temp;
        }
    }
    return -1;
}

int solution(vector<vector<int> > maps)
{
    int answer = BFS(maps);
    return answer;
}