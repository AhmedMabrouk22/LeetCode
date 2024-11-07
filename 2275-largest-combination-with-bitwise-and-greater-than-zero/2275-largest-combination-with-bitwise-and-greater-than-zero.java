class Solution {
    public int largestCombination(int[] candidates) {
        int res = 0 , cnt = 0;
        for(int i = 0 ; i < 24 ; ++i) {
            cnt = 0;
            for(int n : candidates) {
                int x = (n & (1 << i));
                if (x > 0) ++cnt;
            }
            
            res = Math.max(res,cnt);
        }
        return res;
    }
}