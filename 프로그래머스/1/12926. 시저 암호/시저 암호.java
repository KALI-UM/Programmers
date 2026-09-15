class Solution {
    public String solution(String s, int n) {
        String answer = "";
        
        for(int i=0; i<s.length(); i++)
        {
            char target = s.charAt(i);
            if(Character.isLetter(target))
            {
                if(Character.isLowerCase(target))
                    answer += (char)(((int)target+n-(int)'a')%26+(int)'a');
                else
                    answer += (char)(((int)target+n-(int)'A')%26+(int)'A');
            }
            else
            {
                answer += target;
            }
           
        }
        
        return answer;
    }
}