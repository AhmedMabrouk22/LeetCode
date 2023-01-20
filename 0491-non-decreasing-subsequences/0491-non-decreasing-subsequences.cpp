class Solution {
public:
    set<vector<int>>res;
    vector<int>cur;
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        solve(0,nums);
        return vector(res.begin(),res.end());
    }
    
    void solve(int i, vector<int>& nums)
    {
        if (i == nums.size())
        {
            if (cur.size() >= 2)
                res.insert(cur);
            return ;
        }
        
        if (cur.empty() || cur.back() <= nums[i])
        {
            cur.push_back(nums[i]);
            solve(i+1,nums);
            cur.pop_back();
        }
        solve(i+1,nums);
    }
    
};