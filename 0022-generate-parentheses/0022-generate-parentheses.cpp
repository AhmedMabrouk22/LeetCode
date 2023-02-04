class Solution {
public:
    vector<string>res;
    vector<string> generateParenthesis(int n) {
        solve(0,0,n,"");
        return res;
    }
    
    void solve(int open , int close,int n,string str)
    {
        if (str.size() == n*2)
        {
            res.push_back(str);
            return;
        }
        
        if (open < n)
        {
            str += '(';
            solve(open + 1,close,n,str);
            str.pop_back();
        }
        
        if (close < open)
        {
            str += ')';
            solve(open,close + 1,n,str);
            str.pop_back();
        }
    }
    
};