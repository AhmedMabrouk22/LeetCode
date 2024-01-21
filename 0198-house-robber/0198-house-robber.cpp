class Solution {
public:
    int n;
    int memo[105][105];
    int solve(int i , int prv, vector<int>& nums)
    {
        if(i == n) return 0;
        if (memo[i][prv] != -1)
            return memo[i][prv];
        int c1 = solve(i+1,prv,nums);
        int c2 = 0;
        if (prv != i - 1)
            c2 = solve(i+1,i,nums) + nums[i];
        return memo[i][prv] = max(c1,c2);
    }
    int rob(vector<int>& nums) {
        memset(memo,-1,sizeof(memo));
        n = nums.size();
        return solve(0,104,nums);
    }
};