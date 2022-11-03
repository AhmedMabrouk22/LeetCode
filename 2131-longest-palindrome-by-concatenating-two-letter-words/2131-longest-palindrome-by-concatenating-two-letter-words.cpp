class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int>mp;
        bool f = false;
        int n = words.size();
        for(int i = 0 ; i < n; ++i)
            ++mp[words[i]];
        
        int res = 0;
       
        for(auto i : mp)
        {
            string str = i.first;
            string rev = str;
            swap(rev[0],rev[1]);
            if (str == rev)
            {
                if (mp[str] % 2 == 0)
                    res += mp[str];
                
                else 
                {
                    res += mp[str]-1;
                    f = true;
                }
                
            }
            else if (mp.count(rev))
            {
                int x = 2*min(mp[str],mp[rev]);
                res += x;
                mp[str]=mp[rev]=0;
            }
        }
        
        if (f)
            ++res;
        
        return res*2;
    }
};