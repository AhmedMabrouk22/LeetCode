class Solution {
    public int reductionOperations(int[] nums) {
        Arrays.sort(nums);
        int res = 0;
        int cnt = 0;
        
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] != nums[i - 1]) {
                cnt++;
            }
            
            res += cnt;
        }
        
        return res;
    }
}