class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<int>prf(n+5,0) , suf(n+5,0);
        for(int i = 1 ; i <= n ; ++i)
        {
            prf[i] = prf[i-1] + (s[i-1] == '1');
        }
        
        for(int i = n ; i > 0 ; --i)
        {
            suf[i] = suf[i+1] + (s[i-1] == '0');
        }
        
        int res = min(suf[1],prf[n]);
        for(int i = 1;i<n;++i)
        {
            res = min(res,prf[i]+suf[i+1]);
        }
        
        return res;
    }
};