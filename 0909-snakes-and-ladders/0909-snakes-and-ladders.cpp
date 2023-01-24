class Solution {
public:
    
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int idx = 1;
        
        vector<int>col(n);
        iota(col.begin(),col.end(),0);
        
        vector<pair<int,int>>numberOfCells(n*n+1);
        for(int row = n-1;row>=0;--row)
        {
            for(auto i : col)
                numberOfCells[idx++] = {row,i};
            reverse(col.begin(),col.end());
        }
        
        vector<int>len(n*n+1,-1);
        queue<int>q;
        q.push(1);
        len[1] = 0;
        while(!q.empty())
        {
            int cur =q.front();
            q.pop();
            int m = min(cur+6,n*n);
            for(int i = cur+1 ; i<=m;++i)
            {
                auto [row,col] = numberOfCells[i];
                int nxt = board[row][col] != -1 ? board[row][col] : i;
                if (len[nxt] == -1)
                {
                    q.push(nxt);
                    len[nxt] = len[cur] + 1;
                }
            }
        }
        
        return len[n*n];
    }
};