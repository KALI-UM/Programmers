#include <cmath>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
   
    double R1 = pow(r1, 2);
    double R2 = pow(r2, 2);
   
    //x가 정수값일 때, 원1, 원2의 y값 각각 y1, y2을 구한다
    //r1원 내 좌표여야 하기 때문에 //r2원 외 좌표여야 하기 때문에
    //y2보다 작아야 하므로 내림   //y1는 올림 계산을 해서 서로 뺀다.
    for(int x =0; x<r1; x++)
    {
        double y2=0;
        double y1=0;
        y2 = sqrt(R2 - pow(x, 2)); 
        y1 = sqrt(R1 - pow(x, 2));
        answer += floor(y2)-ceil(y1)+1;
    }
    
    for(int x = r1;  x<=r2; x++)
    {
        double y=0; 
        y = sqrt(R2 - pow(x, 2)); 
        answer +=floor(y)+1;
    }    
  
    //1사분면의 결과를 4배 할 것이기 때문에 중복되지 않도록 빼준다.
    answer-=r2-r1+1;
    
    return answer*4;
}