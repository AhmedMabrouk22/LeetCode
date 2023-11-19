class Solution {
    public int reductionOperations(int[] nums) {
        Arrays.sort(nums);
        int[] frq = new int[(int)5e4 + 5];
        for(int i : nums) ++frq[i];
        int res = 0;
        for(int i = nums.length - 1; i > 0 ; --i) {
            if (nums[i] == nums[0]) break;
            if (nums[i] != nums[i-1]) {
                res += frq[nums[i]];
                frq[nums[i-1]] += frq[nums[i]];
            }
        }
        
        return res;

    }
}