class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        vector<int>frq(105);
        for(auto i : nums) 
            ++frq[i];
        
        int res = 0;
        for(auto i : frq)
            res += (i*(i-1)) / 2;
        return res;
    }
};