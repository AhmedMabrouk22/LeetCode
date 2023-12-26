
class Solution {
public:
    
    vector<vector<int>>memo;
    int mod = 1e9 + 7;
    int solve(int n,int k, int target) {
        if (target == 0 && n == 0) return 1;
        if (n == 0 || target <= 0) return 0;

        if (memo[n][target] != -1) return memo[n][target];

        int res = 0;
        for(int i = 1 ; i <= k ; ++i) 
        {
            res = (res + solve(n-1,k,target - i)) % mod;
        }
        return memo[n][target] = res % mod;
    }

    int numRollsToTarget(int n, int k, int target) {
        memo = vector<vector<int>>(n + 5,vector<int>(target + 5,-1));
        return solve(n,k,target);
    }
};