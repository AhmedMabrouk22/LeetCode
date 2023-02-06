class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int l = 0 , r = n;
        vector<int>res(2*n);
        for(int i = 0 ; i < 2*n ; i += 2)
        {
            res[i] = nums[l++];
            res[i+1] = nums[r++];
        }
        
        return res;
    }
};