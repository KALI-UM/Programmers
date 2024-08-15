#include <string>
#include <vector>

using namespace std;

vector<int> G;
int find(int index)
{
    if(G[index]==index)return index;
    else return G[index]=find(G[index]);
}

void Union(int a, int b)
{
    a=find(a);
    b=find(b);
    if(a>b)swap(a,b);
    
    G[b]=a;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    G.resize(n);
    for(int i=0; i<n; i++)
        G[i]=i;
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(i==j)continue;
        if(computers[i][j]==1)
            Union(i,j);
        }  
    }
    
     for(int i=0; i<n; i++)
     {
         if(G[i]==i)answer++;
     }
    
    return answer;
}