class Solution {
public:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    int n,m;
    bool valid(int i, int j)
    {
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    
    void dfs(int i,int j,vector<vector<char>>& grid)
    {
        if (grid[i][j] != '1')
            return;
        grid[i][j] = '#';
        
        for(int a = 0 ; a < 4 ; ++a)
        {
            int x = dx[a] + i;
            int y = dy[a] + j;
            if (valid(x,y))
                dfs(x,y,grid);
        }
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int res = 0;
        for(int i = 0 ; i < n ; ++i)
        {
            for(int j = 0 ; j < m ; ++j)
            {
                if (grid[i][j] == '1')
                {
                    dfs(i,j,grid);
                    ++res;
                }
            }
        }
        
        return res;
        
    }
};