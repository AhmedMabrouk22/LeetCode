class Solution {
    public int minPairSum(int[] nums) {
        Arrays.sort(nums);
        int res = 0 , l = 0 , r = nums.length - 1;
        while (l < r) {
            res = Math.max(res,nums[l] + nums[r]);
            ++l;
            --r;
        }
        return res;
    }
}