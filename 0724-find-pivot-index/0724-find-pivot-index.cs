public class Solution {
    public int PivotIndex(int[] nums) {
        int n = nums.Length;
        int[] prf = new int[n + 5];
        int[] suf = new int[n + 5];
        for(int i = 1 ; i <= n; ++i)
            prf[i] = nums[i-1]+prf[i-1];

        
        for(int i = n; i>=1;--i)
            suf[i] = suf[i+1]+nums[i-1];

        for(int i = 1;i<=n;++i)
        {
            if (prf[i-1] == suf[i+1])
                return i-1;
        }
        
        return -1;
    }
}