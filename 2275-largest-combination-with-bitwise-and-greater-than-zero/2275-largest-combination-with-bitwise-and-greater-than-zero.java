class Solution {
    public int largestCombination(int[] candidates) {
        int []frq = new int[35];
        int res = 0;
        for(int i : candidates) {
            for(int j = 0 ; j < 32; ++j) {
                int x = (i & (1 << j));
                if (x > 0)
                    ++frq[j];
                res = Math.max(res,frq[j]);
            }
        }
        return res;
    }
}