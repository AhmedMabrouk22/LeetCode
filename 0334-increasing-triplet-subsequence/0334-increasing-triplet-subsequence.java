class Solution {
    public boolean increasingTriplet(int[] nums) {
        int n = nums.length;
        if (n < 3) return false;
        int[] mn = new int[n];
        int[] mx = new int[n];
        mn[0] = nums[0];
        for(int i = 1 ; i < n ; ++i) mn[i] = Math.min(mn[i-1], nums[i]);
        
        mx[n-1] = nums[n-1];
        for(int i = n-2; i >= 0 ; --i) mx[i] = Math.max(mx[i+1],nums[i]);
        for(int i = 0 ; i < n ; ++i) {
            if (nums[i] > mn[i] && nums[i] < mx[i]) return true;
        }
        return false;
    }
}