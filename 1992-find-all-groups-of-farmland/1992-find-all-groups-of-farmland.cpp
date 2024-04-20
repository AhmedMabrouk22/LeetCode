class Solution {
public:
    
    int n,m;
    vector<vector<bool>>vis;
    int r2,c2;
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    
    bool valid(int i , int j)
    {
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    
    void dfs(int i,int j,vector<vector<int>>& land)
    {
        if (vis[i][j] || !land[i][j]) return;
        
        vis[i][j] = true;
        r2 = max(r2,i);
        c2 = max(c2,j);
        for(int a = 0 ; a < 4 ; ++a)
        {
            int x = i + dx[a];
            int y = j + dy[a];
            if (valid(x,y))
                dfs(x,y,land);
        }
    }
    
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> res;
        n = land.size();
        m = land[0].size();
        vis = vector<vector<bool>>(n,vector<bool>(m));
        for(int i = 0 ; i < n ; ++i)
        {
            for(int j = 0 ; j < m ; ++j)
            {
                if (land[i][j] && !vis[i][j])
                {
                    r2 = c2 = 0;
                    dfs(i,j,land);
                    res.push_back({i,j,r2,c2});
                }
            }
        }
        
        return res;
    }
};