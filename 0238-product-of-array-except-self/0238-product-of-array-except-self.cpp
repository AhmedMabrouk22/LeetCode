class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>prf(n+1,1),suf(n+2,1);
        for(int i = 1;i<= n ;++i)
            prf[i] = prf[i-1] * nums[i-1];
        
        for(int i = n;i >= 1;--i)
            suf[i] = suf[i+1]*nums[i - 1];
        
        vector<int>res;
        for(int i = 1 ; i <= n ; ++i)
            res.push_back(prf[i-1]*suf[i+1]);
        
        return res;
    }
};