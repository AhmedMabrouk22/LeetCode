class Solution {
    
    public boolean canSortArray(int[] nums) {
        int mxCurSeg = nums[0];
        int mnCurSeg = nums[0];
        int bitsCnt = Integer.bitCount(nums[0]);
        int mxPrvSeg = Integer.MIN_VALUE;

        for(int i = 1 ; i < nums.length; ++i) {
            if (Integer.bitCount(nums[i]) == bitsCnt) {
                mxCurSeg = Math.max(mxCurSeg,nums[i]);
                mnCurSeg = Math.min(mnCurSeg,nums[i]);
            } else {
                if (mnCurSeg < mxPrvSeg) return false;
                mxPrvSeg = mxCurSeg;
                bitsCnt = Integer.bitCount(nums[i]);
                mxCurSeg = nums[i];
                mnCurSeg = nums[i];
            }
        }
        return mnCurSeg >= mxPrvSeg;
    }
}