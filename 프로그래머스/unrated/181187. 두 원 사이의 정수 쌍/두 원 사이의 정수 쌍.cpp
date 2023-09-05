#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
   
    double R1 = pow(r1, 2);
    double R2 = pow(r2, 2);
   
    for(int x =0; x<r1; x++)
    {
        double y2=0;
        double y1=0;
       
        y2 = sqrt(R2 - pow(x, 2)); 
        y1 = sqrt(R1 - pow(x, 2));
        //cout<<"y2-"<<floor(y2)<<" y1-"<<ceil(y1)<<endl;
        answer += floor(y2)-ceil(y1)+1;
    }
    
    for(int x = r1;  x<=r2; x++)
    {
        double y=0; 
        y = sqrt(R2 - pow(x, 2)); 
        //cout<<"y-"<<floor(y)<<endl;
        answer +=floor(y)+1;
    }
    
    answer-=r2-r1+1;
    
    return answer*4;
}