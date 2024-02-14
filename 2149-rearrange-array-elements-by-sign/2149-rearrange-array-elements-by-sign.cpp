class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>p,n;
        for(auto i : nums) 
        {
            if (i >= 0) p.push_back(i);
            else n.push_back(i);
        }
        vector<int>res;
        int a = 0;
        while(a < p.size())
        {
            res.push_back(p[a]);
            res.push_back(n[a]);
            ++a;
        }
        return res;
        
    }
};