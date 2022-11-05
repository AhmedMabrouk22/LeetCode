class Solution {
    
    vector<string>res;
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    
    struct Node
    {
        bool isEnd;
        string word;
        Node *child[26];
        Node()
        {
            isEnd = false;
            word = "";
            for(int i = 0; i < 26; ++i)
                child[i] = NULL;
        }
    };
    
    Node *root = new Node();
    
    void insert(string &s)
    {
        Node *cur = root;
        for(int i = 0 ; i < s.size();++i)
        {
            int idx = s[i]-'a';
            
            if (cur->child[idx] == NULL)
                cur->child[idx] = new Node();
            
            cur = cur->child[idx];
            
        }
        
        cur->isEnd = true;
        cur->word = s;
                
    }
    
    
    bool valid(int r,int c,vector<vector<char>>& board)
    {
        int n = board.size();
        int m = board[0].size();
        return r>=0 && r < n && c >= 0 && c < m && board[r][c] != '#';
    }
    
    void dfs(vector<vector<char>>& board,int r,int c , Node *cur)
    {
        
        
        int idx = board[r][c] - 'a';
        
        if (cur->child[idx] == NULL)
            return;
        
        cur= cur->child[idx];
        
        if (cur->isEnd)
        {
            
            
            res.push_back(cur->word);
            cur->isEnd = false;
        }
        
        char val = board[r][c];
        board[r][c] = '#';
        for(int i = 0 ; i < 4 ;++i)
        {
            int x = r+dx[i];
            int y = c+dy[i];
            if (valid(x,y,board))
                dfs(board,x,y,cur);
        }
        
        board[r][c] = val;
        
    }
    
    
    
public:
    
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        int n = board.size();
        int m = board[0].size();
        
        for(auto i : words)
            insert(i);
        
        for(int i = 0 ; i < n ; ++i)
        {
            for(int j = 0 ; j < m ; ++ j)
            {
                dfs(board,i,j,root);
            }
        }
        return res;
    }
};
