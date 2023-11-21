class Solution {
    public int longestSubarray(int[] nums) {
        int n = nums.length;
        int l = 0 , r = 0 , k = 0 , cnt = 0 , res = 0;
        boolean f = false;
        while (l < n) {
            while (r < n && k <= 1) {
                if (nums[r] == 1) ++cnt;
                else {
                    ++k;
                    f = true;
                }
                ++r;
            }
            res = Math.max(res,cnt);
            k -= (nums[l] == 0 ? 1 : 0);
            cnt -= (nums[l] == 1 ? 1 : 0);
            ++l;
        }
        return res - (!f ? 1 : 0);
    }
}