class Solution {
    public String largestGoodInteger(String num) {
        String mx = "";
        for(char i = '0' ; i <= '9' ; ++i) {
            String str = String.format("%c%c%c",i,i,i);
            if (num.contains(str))
                mx = str;
        }
        return mx;
    }
}