class Solution {
    public int solution(int[][] sizes) {
        int answer = 0;
        
        int maxWid=0;
        int maxHei=0;
        
        for(int[] size :sizes)
        {
            int wid=Math.max(size[0], size[1]);
            int hei = Math.min(size[0], size[1]);
            
            if(maxWid<wid)
                maxWid=wid;
            
            if(maxHei<hei)
                maxHei=hei;
        }
        
        
        answer= maxWid*maxHei;
        return answer;
    }
}