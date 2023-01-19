class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>prf(n+1);
        for(int i = 1 ; i <= n ; ++i)
            prf[i] = prf[i-1] + nums[i-1];
        for(int i = 1 ; i <= n ; ++i)
            prf[i] =((prf[i]%k)+k) % k;
        
        int res = 0;
        unordered_map<int,int>frq;
        frq[0] = 1;
        for(int i = 1 ; i <= n ; ++i)
        {
            res += frq[prf[i]];
            ++frq[prf[i]];
        }
        
        return res;
    }
};