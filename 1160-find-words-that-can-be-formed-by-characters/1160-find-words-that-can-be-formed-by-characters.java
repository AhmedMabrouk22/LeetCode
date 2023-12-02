import java.util.HashMap;
import java.util.Map;

class Solution {
    public int countCharacters(String[] words, String chars) {
        int res = 0;
        Map<Character, Integer> mp1 = new HashMap();
        
        for(char c : chars.toCharArray()) {
            mp1.put(c, mp1.getOrDefault(c, 0) + 1);
        }


        for(String str : words) {
            Map<Character, Integer> mp2 = new HashMap();

            for(char c : str.toCharArray()) 
                mp2.put(c,mp2.getOrDefault(c, 0) + 1);

            boolean f = true;
            for(char c : str.toCharArray()) {
                if (mp1.getOrDefault(c, 0) < mp2.get(c)) {
                    f = false;
                    break;
                }
            }

            if (f) res += str.length();

        }

        return res;
    }
}