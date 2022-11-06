class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0 , r = nums.size() - 1;
        while(l <= r)
        {
            int mid = (l+r)>>1;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                r = mid - 1;
            else 
                l = mid + 1;
        }
        return -1;
    }
};