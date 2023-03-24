class Solution {
public:
    int search(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        for(int i = 0 ; i < nums.size() ; ++i)
            mp[nums[i]] = i;
        
        return (mp.count(target) ? mp[target] : -1);
    }
};