class Solution {
public:
    int part(vector<int>& nums, int start,int end,int pivot)
    {
        int i = start , j = start;
        while(j <= end)
        {
            if (nums[j] <= pivot)
            {
                swap(nums[j],nums[i]);
                ++i;
                ++j;
            }
            else 
                ++j;
        }
        return i-1;
    }
    
    
    int solve(vector<int>& nums,int start ,int end , int k)
    {
        int pivot = nums[end];
        int p = part(nums,start,end,pivot);
        
        if (p < k)
            return solve(nums,p+1,end,k);
        else if(p > k)
            return solve(nums,start,p-1,k);
        
        return nums[p];
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        k = n - k;
        
        return solve(nums,0,n-1,k);
    }
};