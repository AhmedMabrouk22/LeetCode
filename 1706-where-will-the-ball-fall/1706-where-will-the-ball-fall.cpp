class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int sz = grid[0].size();
        vector<int>res(sz,0);
        
        for(int i = 0 ; i < sz;++i)
            res[i] = findDropColumn(0,i,grid);
        return res;
    }
    
    int findDropColumn(int row,int col,vector<vector<int>>& grid)
    {
        int sz = grid.size();
        if (row == sz)
            return col;
        
        int nxt_col = col+grid[row][col];
        if (nxt_col < 0 || nxt_col > grid[0].size()-1 || grid[row][col] != grid[row][nxt_col])
            return -1;
        return findDropColumn(row+1,nxt_col,grid);
    }
    
};