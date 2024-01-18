public class Solution
{
    int[] memo;
    int solve(int n)
    {
        if (n <= 0)
            return 1;
        if (memo[n] != -1)
            return memo[n];
        int res = 0;
        res += solve(n - 1);
        if(n >= 2)
            res += solve(n - 2);
        return memo[n] = res;
    }
    public int ClimbStairs(int n)
    {
        memo = new int[50];
        for (int i = 0; i < 50; ++i)
            memo[i] = -1;
        return solve(n);
    }
}