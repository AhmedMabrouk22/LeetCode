class Solution {
public:
    int minSteps(string s, string t) {
        map<char,int>mp;
        int cnt = 0;
        for(auto i : s) 
        {
            ++mp[i];
            ++cnt;
        }

        for(auto i : t)
        {
            if (mp[i])
            {
                --cnt;
                --mp[i];
            }
        }

        return cnt;

    }
};