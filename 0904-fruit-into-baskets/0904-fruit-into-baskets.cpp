class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int res =  0;
        unordered_map<int,int>mp;
        int l = 0,r = 0;
        int n = fruits.size();
        while(l < n && r < n)
        {
            ++mp[fruits[r]];
            ++r;
            
            
            if (mp.size() > 2)
            {
                --mp[fruits[l]];
                if (!mp[fruits[l]])
                    mp.erase(fruits[l]);
                ++l;
            }
            
            int cnt = 0;
            for(auto x : mp)
                cnt += x.second;
            res = max(res,cnt);
        }

        return res;
    }
};