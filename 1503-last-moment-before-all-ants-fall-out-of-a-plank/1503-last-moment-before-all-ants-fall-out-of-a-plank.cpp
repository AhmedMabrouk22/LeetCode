class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int res = 0;
        for(auto i : left)
            res = max(i,res);
        for(auto i : right)
            res= max(n - i,res);
        
        return res;
    }
};