class Solution {
public:
    
    vector<int> dx = {0,  0, 1, -1};
    vector<int> dy = {1, -1, 0,  0};
    int n;
    
    bool valid(int r,int c)
    {
        return r >= 0 && r < n && c>= 0 && c <n;
    }
    
    int maxDistance(vector<vector<int>>& grid) {
        n = grid.size();
        map<pair<int,int>,int>len;
        queue<pair<int,int>>q;
        for(int i = 0 ; i < n ; ++i)
        {
            for(int j = 0 ; j < n ; ++j)
            {
                if (grid[i][j])
                {
                    q.push({i,j});
                    len[{i,j}] = 0;
                }
                
            }
        }
        
        while(!q.empty())
        {
            pair<int,int>cur = q.front();
            q.pop();
            
            for(int i = 0 ; i < 4 ; ++i)
            {
                int x = cur.first + dx[i];
                int y = cur.second + dy[i];
                
                if (valid(x,y) && !len.count({x,y}) && !grid[x][y])
                {
                    q.push({x,y});
                    len[{x,y}] = len[{cur.first,cur.second}] + 1;
                }
                    
            }
            
        }
        
        int res = 0;
        for(auto i : len)
            res = max(res,i.second);
        
        return (!res ? -1 : res);
    }
};