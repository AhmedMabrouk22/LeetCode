class Solution {
    public int maxOperations(int[] nums, int k) {
        Arrays.sort(nums);
        int n = nums.length;
        int l = 0 , r = n - 1;
        int cnt = 0;
        while (l < r) {
            if (nums[l] + nums[r] == k) {
                ++cnt;
                ++l;
                --r;
            } else if (nums[l] + nums[r] > k) 
                --r;
            else 
                ++l;
        }
        return cnt;
    }
}