#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int,int>mp;
        int mx = 0;
        for(auto i : nums) {
            ++mp[i];
            mx = max(mx,mp[i]);
        }

        vector<vector<int>>res(mx);
        for(auto i : mp)
        {
            for(int x = 0 ; x < i.second ; ++x)
                res[x].push_back(i.first);
        }

        return res;
    }
};