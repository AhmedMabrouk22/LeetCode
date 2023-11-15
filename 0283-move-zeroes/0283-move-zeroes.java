public class Solution {
    public void moveZeroes(int[] nums) {
        int n = nums.length;
        int idx = 0;
        for(int i : nums) {
            if (i != 0) {
                nums[idx] = i;
                ++idx;
            }
        }
        while (idx < n) {
            nums[idx] = 0;
            ++idx;
        }
        
    }
}
