class Solution {
public:
    
    int memo[(int)1e4+5];
    int n;
    int solve(int i, vector<int>& nums)
    {
        if (i >= n - 1)
            return 0;
        if (memo[i] != -1)
            return memo[i];
        
        memo[i] = 1e5;
        for(int j=0;j<=nums[i];++j)
            memo[i] = min(memo[i],solve(i+j,nums) + 1);
        return memo[i];
    }
    int jump(vector<int>& nums) {
        n = nums.size();
        memset(memo,-1,sizeof(memo));
        
        return solve(0,nums);
    }
};