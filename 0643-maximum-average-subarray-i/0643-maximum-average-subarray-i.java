class Solution {
    public double findMaxAverage(int[] nums, int k) {
        double res = 0;
        int n = nums.length;
        int l = 0 , r = k;
        for(int i = 0 ; i < k ; ++i) res += nums[i];
        double sum = res;
        res /= k;
        while (l < n && r < n) {
            sum += nums[r];
            sum -= nums[l];
            res = Math.max(res,sum/k);
            ++r;
            ++l;
        }
        return res;
    }
}