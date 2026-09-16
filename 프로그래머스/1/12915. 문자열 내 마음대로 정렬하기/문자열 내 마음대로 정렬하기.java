import java.util.*;

class Solution {
    public String[] solution(String[] strings, int n) {
        String[] answer = {};
        
        List<Pair> pairStrings = Arrays.stream(strings).map(str->new Pair(str.charAt(n), str)).
            sorted(Comparator.comparing((Pair pair)->pair.c).thenComparing((Pair pair)->pair.str)).toList();
         

      answer = new String[pairStrings.size()];

        for (int i = 0; i < pairStrings.size(); i++) {
            answer[i] = pairStrings.get(i).str;
        }
        return answer;
    }
    
    class Pair
    {
        public char c;
        public String str;
        
        public Pair(char c, String str)
        {
            this.c=c;
            this.str=str;
        }
    }
}