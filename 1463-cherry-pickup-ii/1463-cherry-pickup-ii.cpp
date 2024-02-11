class Solution {
public:
    int fun(vector<vector<int>>& grid, vector<vector<vector<int>>>& dp, int i, int j1, int j2){
        if(i == grid.size())return 0;
        if(dp[i][j1][j2] != -1)return dp[i][j1][j2];

        int mx = 0, val = 0;
        for(int a = -1; a < 2; a++){
            for(int b = -1; b < 2; b++){
                int l = j1 + a;
                int r = j2 + b;
                if(l >= 0 && r < grid[0].size() && r >= 0 && l < grid[0].size()){
                    val = grid[i][j1];
                    if(j1 != j2)val += grid[i][j2];
                    mx = max(mx, fun(grid, dp, i + 1, l, r) + val);
                }
            }
        }
        return dp[i][j1][j2] = mx;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return fun(grid, dp, 0, 0, m - 1);
    }
};