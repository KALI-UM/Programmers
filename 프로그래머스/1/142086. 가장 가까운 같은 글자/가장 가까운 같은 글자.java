import java.util.*;

class Solution {
    public int[] solution(String s) {
        int[] answer = new int[s.length()];
        
        int[] strIndices = new int[26];
        Arrays.fill(strIndices, -1);


        for(int i=0; i<s.length(); i++)
        {
            char curr = s.charAt(i);
            int index = strIndices[(int)curr-(int)'a'];
            if(index==-1)
                answer[i]=index;
            else
                answer[i]=i-index;
            strIndices[(int)curr-(int)'a'] = i;
        }
        
        
        return answer;
    }
}