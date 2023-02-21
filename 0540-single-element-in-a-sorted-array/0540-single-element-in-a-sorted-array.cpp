class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        int l = 0 , r = nums.size();
        while(l <= r)
        {
            int mid = (l+r)>>1;
            if (mid < nums.size() - 1 && nums[mid] == nums[mid+1])
                mid = mid + 1;
            else if (mid > 0 && nums[mid] != nums[mid-1])
                return nums[mid];
            else if (mid == 0 && nums[mid] != nums[mid+1])
                return nums[mid];
            
            if (mid % 2 == 0)
                r = mid - 1;
            else 
                l = mid+1;
        }
        return r;
    }
};