class Solution {
public:
    
    int n,m;
    vector<vector<char>> grid;
    string str;
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    bool valid(int i,int j)
    {
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    
    bool solve(int i,int j,int idx)
    {
        if (idx == str.size())
            return true;
        
        if (!valid(i,j) || grid[i][j] == '#'|| str[idx] != grid[i][j]) return false;
        
        char cur = grid[i][j];
        grid[i][j] = '#';
        
        for(int a = 0 ; a < 4 ; ++a)
        {
            int x = i + dx[a];
            int y = j + dy[a];
            if (solve(x,y,idx + 1))
                return true;
        }
        
        grid[i][j] = cur;
        
        return false;
        
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        grid = board;
        str = word;
        n = board.size();
        m = board[0].size();
        for(int i = 0 ; i < n ; ++i)
        {
            for(int j = 0 ; j < m ; ++j)
            {
                if (solve(i,j,0)) return true;
            }
        }
        
        return false;
    }
};