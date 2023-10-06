class Solution {
public:
    //int memo[58][1000000];
    map<pair<int,int>,int>memo;
    int x;
    int solve(int sum , int prod) 
    {
        if (sum == x)
            return prod;
        if (memo.count({sum,prod}))
            return memo[{sum,prod}];
        
        int res = 0;
        for(int i = 1 ; i < x ; ++i )
        {
            if (sum + i <= x)
                res = max(res,solve(sum+i,prod*i));
        }
        
        return memo[{sum,prod}] = res;
        
    }
    int integerBreak(int n) {
        x = n;
        // memset(memo,-1,sizeof(memo));
        return solve(0,1);
    }
};