class Solution {
public:
    
    vector<int>ans;
    set<vector<int>>res;
    
    void solve(int idx,vector<int>& nums) 
    {
        if (idx == nums.size())
        {
            res.insert(ans);
            return;
        }
        
            ans.push_back(nums[idx]);
            solve(idx+1,nums);
            ans.pop_back();
            solve(idx+1,nums);
        
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        solve(0,nums);
        vector<vector<int>>out;
        for(auto i : res)
            out.push_back(i);
        return out;
    }
};


