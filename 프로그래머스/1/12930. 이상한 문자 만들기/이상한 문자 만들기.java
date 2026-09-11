import java.util.*;

class Solution {
    public String solution(String s) {
        
        return func(s);
    }
    
    public static String func(String str)
    {
        int spaceIndex=0;
        String result="";
        for(int i=0; i<str.length(); i++)
        {
            if(str.charAt(i)==' ')
            {
                spaceIndex=0;
                result+=str.charAt(i);
                continue;                
            }
            
            result=result+(spaceIndex%2==0? Character.toUpperCase(str.charAt(i)) : Character.toLowerCase(str.charAt(i)));
            spaceIndex++;
        }
        return result;
    }
}