class Solution {

    boolean valid(char i) {
        return i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u';
    }
    public int maxVowels(String s, int k) {
        int res = 0, cnt = 0;
        for(int i = 0 ; i < k ; ++i) {
            if (valid(s.charAt(i))) ++cnt;
        }
        res = Math.max(res,cnt);
        int l = 0 , r = k;
        while (l < s.length() && r < s.length()) {
            cnt += (valid(s.charAt(r)) == true ? 1 : 0);
            cnt -= (valid(s.charAt(l)) == true ? 1 : 0);
            ++l;
            ++r;
            res = Math.max(res,cnt);
        }
        return Math.max(res,cnt);
    }
}