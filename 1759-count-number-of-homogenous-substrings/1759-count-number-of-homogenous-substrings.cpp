class Solution {
public:
    int countHomogenous(string s) {
        int mod = 1e9 + 7;
        long long cnt = 1;
        int res = 0;
        for(int i = 1 ; i <= s.size(); ++i) 
        {
            if (i == s.size() || s[i-1] != s[i])
            {
                long long x = (cnt*(cnt+1))/2;
                res = ((res % mod) + (x % mod))%mod;
                cnt = 1;
            } else ++cnt;
        }
        return res;
    }
};