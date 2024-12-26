#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board) {
    int n = board.size();
    int answer = n*n;
    int danger=0;
    int d[8][2] = {{-1,-1}, {-1, 0}, {-1, 1}, {0,-1}, {0,1},{1,-1},{1,0},{1,1}};
    
    for(int j=0; j<n; j++)
    for(int i=0; i<n; i++)
    {
        if(board[j][i]==1)
        {
            danger++;
            for(int dir=0; dir<8; dir++)
            {
                int temp[2] = {j+d[dir][0], i+d[dir][1]};
                if(temp[0]<0||temp[0]>=n||temp[1]<0||temp[1]>=n||board[temp[0]][temp[1]]!=0)
                    continue;
                
                danger++;
                board[temp[0]][temp[1]]=2;
            }
        }
    }
    answer-=danger;
    return answer;
}