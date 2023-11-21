class Solution {
    public int largestAltitude(int[] gain) {
        int[] prf = new int[gain.length + 1];
        int res = 0;
        for(int i = 1 ; i <= gain.length ; ++i) {
            prf[i] += prf[i-1] + gain[i-1];
            res = Math.max(res,prf[i]);
        }
        return res;
    }
}