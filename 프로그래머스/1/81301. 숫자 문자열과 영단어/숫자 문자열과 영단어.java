import java.util.*;

class Solution {
    public int solution(String s) {
        int answer = 0;
       
        List<String> numberStrings = 
         List.of(
            "zero","one","two","three","four","five","six","seven","eight","nine");
        
        String tempAnswer="";
        String currStringNum="";
        for(int i=0; i<s.length();i++)
        {
            char target = s.charAt(i);
            if(Character.isLetter(target))
            {
                currStringNum+=target;
                // int index = IntStream.range(0, numberStrings.size())
                //         .filter(j -> currStringNum.equals(numberStrings.get(j))).findFirst().orElse(-1);
                int index = numberStrings.indexOf(currStringNum); 
                
                if(index==-1)
                    continue;
                tempAnswer+=(char)((int)'0'+index);
                currStringNum="";
            }
            else
                tempAnswer+=target;
        }
        
        answer = Integer.parseInt(tempAnswer);
        
        return answer;
    }
}