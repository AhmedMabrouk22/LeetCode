class Solution {
public:
    int maxDepth(string s) {
        int res = 0;
        int cnt = 0;
        for (auto i : s)
        {
            if (i == '(') 
                ++cnt;
            else if (i == ')')
                --cnt;
            res = max(res, cnt);
        }
        return res;
    }
};