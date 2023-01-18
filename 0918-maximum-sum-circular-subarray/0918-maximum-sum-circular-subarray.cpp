class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int curMax = 0 , maxSum = INT_MIN;
        int curMin = 0 , minSum = INT_MAX;
        int total = 0;
        for(auto i : nums)
        {
            curMax = max(i,curMax + i);
            maxSum = max(maxSum,curMax);
            
            curMin = min(i,curMin+i);
            minSum = min(minSum,curMin);
            total += i;
        }
        
        return (maxSum > 0 ? max(maxSum,total - minSum) : maxSum);
        
        
    }
};