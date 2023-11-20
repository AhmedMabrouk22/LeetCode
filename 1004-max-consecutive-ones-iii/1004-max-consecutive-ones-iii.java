class Solution {
    public int longestOnes(int[] nums, int k) {
        int res = 0 , cnt = 0 , l = 0 , r = 0 , flip = 0;
        int n = nums.length;
        while (l < n && r < n) {
            if (nums[r] == 0) {
                cnt += 1;
                flip += 1;
            } else cnt += 1;

            if (flip > k) {
                while (l < n && nums[l] == 1) {
                    cnt -= 1;
                    ++l;
                }
                flip -= 1;
                cnt -= 1;
                ++l;
            }
            ++r;
            res= Math.max(cnt,res);
        }
        return res;
    }
}