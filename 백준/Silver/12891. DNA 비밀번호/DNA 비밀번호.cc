#include<iostream>
#include<vector>

using namespace std;
int main()
{
    int N,M;
    cin>>N;
    cin>>M;
    
    string DNA;
    cin>>DNA;
    
    vector<int>ACGT(4,0);
    for(int i=0; i<4; i++)
        cin>>ACGT[i];
    
    int answer=0;
    vector<int>acgt(4,0);
    for(int i=0; i<M; i++)
    {
        if(DNA[i]=='A')
            acgt[0]+=1;
        else if(DNA[i]=='C')
            acgt[1]+=1;
        else if(DNA[i]=='G')
            acgt[2]+=1;
        else if(DNA[i]=='T')
            acgt[3]+=1;
    }
    
    for(int i=0; i<N-M+1; i++)
    {
        if(ACGT[0]<=acgt[0]&&
          ACGT[1]<=acgt[1]&&
          ACGT[2]<=acgt[2]&&
          ACGT[3]<=acgt[3])
            answer++;
        
       if(DNA[i]=='A')
            acgt[0]-=1;
        else if(DNA[i]=='C')
            acgt[1]-=1;
        else if(DNA[i]=='G')
            acgt[2]-=1;
        else if(DNA[i]=='T')
            acgt[3]-=1;
        
        if(DNA[i+M]=='A')
            acgt[0]+=1;
        else if(DNA[i+M]=='C')
            acgt[1]+=1;
        else if(DNA[i+M]=='G')
            acgt[2]+=1;
        else if(DNA[i+M]=='T')
            acgt[3]+=1;
    }
    
    cout<<answer;
}