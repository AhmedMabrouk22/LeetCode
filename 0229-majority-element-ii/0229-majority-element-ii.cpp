class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int x = n / 3;
        map<int,int>frq;
        for(auto i : nums) ++frq[i];
        vector<int>res;
        for(auto i : frq) 
        {
            if (i.second > x)
                res.push_back(i.first);
        }
        
        return res;
    }
};