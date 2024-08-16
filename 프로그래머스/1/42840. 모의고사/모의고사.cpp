#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
   int supoza[3][10]={{1,2,3,4,5,1,2,3,4,5},{2,1,2,3,2,4,2,5,0,0},{3,3,1,1,2,2,4,4,5,5}};
    
    int s0=0; int s1=0; int s2=0;
    for(int i=0; i<answers.size(); i++)
    {
        if(answers[i]==supoza[0][i%10])s0++;
        if(answers[i]==supoza[1][i%8])s1++;
        if(answers[i]==supoza[2][i%10])s2++;
    }
    
    if(s0>=s1&&s0>=s2)
        answer.push_back(1);
    if(s1>=s0&&s1>=s2)
        answer.push_back(2);
    if(s2>=s0&&s2>=s1)
        answer.push_back(3);
    
    return answer;
}