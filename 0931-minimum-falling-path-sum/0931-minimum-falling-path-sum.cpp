class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        if (m == 1 || n == 1) return matrix[0][0];

        vector<vector<int>> dp(m,vector<int>(n, INT_MAX));
        int ans = INT_MAX;

        for (int i = 0; i < matrix.size(); ++i) {
            ans = min(ans, solve(matrix, 0, i, dp));
        }

        return ans;
    }
    
    int solve(vector<vector<int>>& A, int row, int col,  vector<vector<int>>& dp) {
        int m = A.size();
        int n = A[0].size();

        if (dp[row][col] != INT_MAX) return dp[row][col];

        if (row == m - 1)
            return dp[row][col] = A[row][col];

        int left = INT_MAX, right = INT_MAX;

        if (col > 0)
            left = solve(A, row + 1, col - 1, dp);

        int straight = solve(A, row + 1, col, dp);

        if (col < n - 1)
            right = solve(A, row + 1, col + 1, dp);

        dp[row][col] = min(left, min(straight, right)) + A[row][col];

        return dp[row][col];
    }
};