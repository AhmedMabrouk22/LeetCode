class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>frq;
        for(auto i : nums)
            ++frq[i];
        
        map<int,vector<int>>mp;
        for(auto i : frq)
            mp[-i.second].push_back(i.first);
        
        vector<int>res;
        for(auto i : mp)
        {
            for(int x = 0 ; x < i.second.size() && k-- > 0; ++x)
                res.push_back(i.second[x]);
        }
        return res;
    }
};