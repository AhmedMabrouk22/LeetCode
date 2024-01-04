class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int,int>mp;
        for(auto i : nums) ++mp[i];
        int res = 0;
        for(auto i : mp)
        {
            if (i.second == 1)
                return -1;
            res += ceil(double(i.second) / 3);
        }
        return res;
    }
};