class Solution {
    public String sortVowels(String s) {
        int[] frq = new int[300];
        for(int i = 0 ; i < s.length(); ++i)
            ++frq[s.charAt(i)];
        
        StringBuilder res = new StringBuilder();
        String str = "AEIOUaeiou";
        for(int i = 0 ; i < s.length(); ++i) {
            if (str.indexOf(s.charAt(i)) != -1) {
                for(int j = 0 ; j < str.length(); ++j) {
                    if (frq[str.charAt(j)] > 0) {
                        res.append(str.charAt(j));
                        --frq[str.charAt(j)];
                        break;
                    }
                }
            } else res.append(s.charAt(i));
        }
        
        return res.toString();
        
    }
}