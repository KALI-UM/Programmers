class Solution {
    public int[] solution(int n, int m) {
        int[] answer = {};
        
    
        if(n>m)
        {
            int tmp=m;
            m=n;
            n=tmp;
        }
        
        int a=1; int b=m;
        
        for(int i=2; i<=n; i++)
        {
            if(a>i)
                continue;
            
            if(n%i==0&&m%i==0)
            {
                a=i;
            }
        }
        
        b= a* n/a*m/a;
        
        answer = new int[]{a, b};
        return answer;
    }
}