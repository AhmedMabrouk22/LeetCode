class Solution {
    public String mergeAlternately(String word1, String word2) {
        int i = 0;
        StringBuilder res = new StringBuilder();
        while(i < word1.length() && i < word2.length())
        {
            res.append(word1.charAt(i));
            res.append(word2.charAt(i));
            ++i;
        }
        while(i < word1.length())
        {
            res.append(word1.charAt(i));
            ++i;
        }
        while(i < word2.length())
        {
            res.append(word2.charAt(i));
            ++i;
        }
        return res.toString();
    }
}