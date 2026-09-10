import java.util.*;
import java.lang.Math;

class Solution {
    public int solution(int n) {
        int answer = 0;
        
        String num3=three("",n);
    
        
        for(int i=0; i<num3.length(); i++)
        {
            answer+=Character.getNumericValue(num3.charAt(i))*Math.pow(3.0,i);
        }
        return answer;
    }
    
    
    public static String three(String result, int num)
    {
        if(num<3)
            return Integer.toString(num%3)+result;
        else
            return three(Integer.toString(num%3)+result, num/3);
    }
    
    
}