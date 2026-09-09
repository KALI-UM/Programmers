import java.util.*;

class Solution {
    public int[] solution(int n, int m) {
        int[] answer = new int[2];
        
        if(n>m)
        {
            int tmp=m;
            m=n;
            n=tmp;
        }
        
        answer[0]=gcd(m,n);
        answer[1] =n*m/answer[0];

        return answer;
    }
    
    public static int gcd(int a,int b)
    {
        if(b==0)return a;
        return gcd(b, a%b);
    }
}

