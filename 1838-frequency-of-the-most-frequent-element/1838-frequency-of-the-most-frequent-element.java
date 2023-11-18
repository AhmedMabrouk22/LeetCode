class Solution {
    public int maxFrequency(int[] nums, int k) {
        Arrays.sort(nums);
        int n = nums.length;
        int res = 0;
        long sum = 0;
        int l = 0 , r = 0;
        while (r < n) {
            sum += nums[r];
            while (nums[r] * (r - l + 1) > sum + k)
            {
                sum -= nums[l];
                ++l;
            }

            res = Math.max(res,(r - l + 1));
            ++r;
        }
        return res;
    }
}