public class Solution {
    public void moveZeroes(int[] nums) {
        int n = nums.length;
        int l = 0;
        while (l < n) {
            int r = l;
            while (r < n && nums[r] == 0) ++r;

            if (nums[l] == 0 && r < n) {
                int temp = nums[l];
                nums[l] = nums[r];
                nums[r] = temp;
            }
            ++l;
        }
    }
}
