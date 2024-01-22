class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        map<int,int>mp;
        vector<int>v;
        for(auto i : nums) ++mp[i];
        for(auto i : mp) 
        {
            if (i.second == 2) v.push_back(i.first);
        }
        
        for(int i = 1 ;i <= nums.size(); ++i)
        {
            if (!mp[i]) v.push_back(i);
        }
        
        return v;
    }
};