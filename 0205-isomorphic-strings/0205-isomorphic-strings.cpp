class Solution {
public:
   
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        unordered_map<char,char>mp1,mp2;
        for(int i = 0 ; i < n ; ++i)
        {
            if (!mp1.count(s[i]) && !mp2.count(t[i]))
            {
                mp1[s[i]] = t[i];
                mp2[t[i]] = s[i];
            } else if (mp1[s[i]] != t[i] || mp2[t[i]] != s[i])
                return false;
        }
        
        return true;
    }
};