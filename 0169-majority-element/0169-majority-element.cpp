class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int x = n / 2;
        unordered_map<int,int>frq;
        for(auto i : nums) 
        {
            ++frq[i];
            if(frq[i] > x) return i;
        }
        return 0;
    }
};