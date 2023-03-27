public class Solution
{
    private int m,n;
    private int[,] memo;

    int solve(int i, int j, int[][] grid)
    {
        if (i >= m || j >= n)
            return (int)1e9;
            
        if (i == m - 1 && j == n - 1)
            return grid[i][j];
                
        if (memo[i, j] != -1)
            return memo[i, j];
        int c1 = solve(i + 1, j,grid) + grid[i][j];
        int c2 = solve(i, j + 1, grid) + grid[i][j];
        return memo[i, j] = Math.Min(c1, c2);
    }
    public int MinPathSum(int[][] grid)
    {
        m = grid.Length;
        n = grid[0].Length;
        memo = new int[m, n];
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
                memo[i, j] = -1;
        }
        return solve(0,0,grid);
    }
}