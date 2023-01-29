class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>>res;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        
        for(int i = 0 ; i < n ; ++i)
        {
            int j = i + 1;
            int k = n - 1;
            while(j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0)
                {
                    res.insert({nums[i],nums[j],nums[k]});
                    ++j;
                    --k;
                }else if (sum < 0)
                    ++j;
                else 
                    --k;
                
            }
        }
        
        vector<vector<int>>out;
        for(auto i : res)
            out.push_back(i);
        
        return out;
    }
};