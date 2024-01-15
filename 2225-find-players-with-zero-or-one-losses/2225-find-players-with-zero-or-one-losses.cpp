class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int>mp;
        for(auto i : matches)
        {
            ++mp[i[1]];
            if (!mp[i[0]]) mp[i[0]] = 0;
        }
        vector<int>v1,v2;
        for(auto i : mp)
        {
            if (i.second == 1) v1.push_back(i.first);
            if (!i.second) v2.push_back(i.first);
        }
        
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        vector<vector<int>> res;
        res.push_back(v2);
        res.push_back(v1);
        return res;
    }
};