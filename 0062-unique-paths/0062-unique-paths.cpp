class Solution {
public:
    int memo[105][105];
    int mod = 2e9;
    int solve(int i,int j,int m,int n) {
        if (i == m-1 && j == n-1)
            return 1;
        if (memo[i][j] != -1)
            return memo[i][j];
        int c1 = 0;
        if (i < m)
            c1 += solve(i+1,j,m,n) % mod;
        if (j < n)
            c1 += solve(i,j+1,m,n) % mod;
        return memo[i][j]= c1 % mod;
    }
    int uniquePaths(int m, int n) {
        memset(memo,-1,sizeof(memo));
        return solve(0,0,m,n);
    }
};