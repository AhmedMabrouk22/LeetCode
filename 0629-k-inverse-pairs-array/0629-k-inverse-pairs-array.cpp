class Solution {
public:
    int memo[1005][1005];
    int mod = 1e9 + 7;
    int solve(int i,int rem,int n)
    {
        if (i >= n)
        {
            if (rem == 0) return 1;
            return 0;
        }
        if (memo[i][rem] != -1) return memo[i][rem];
        
        int res = 0;
        for(int j = 0 ; j <= min(rem, n - i); ++j)
        {
            res += solve(i+1,rem - j,n);
            res %= mod;
        }
        return memo[i][rem] = res;
    }
        
    int kInversePairs(int n, int k) {
        memset(memo,-1,sizeof(memo));
        return solve(1,k,n);
    }
};