class Solution {
public:
    string orderlyQueue(string s, int k) {
        
        if (k == 1)
        {
            
            string res = s;
            int n = s.size();
            for(int i = 0 ; i < n ; ++i)
            {
                char x = s[n-1];
                s.pop_back();
                s = x + s;
                res = min(res,s);
            }
            return res;
        }
        
        sort(s.begin(),s.end());
        return s;
        
    }
};