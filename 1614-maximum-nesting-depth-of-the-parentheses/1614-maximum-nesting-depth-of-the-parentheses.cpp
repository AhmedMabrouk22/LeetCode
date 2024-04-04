class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int res = 0;
        for (auto i : s)
        {

            if (i == '(') 
                st.push('(');

            if (!st.empty() && i == ')')
                st.pop();

            res = max(res, (int)st.size());
        }
        return res;
    }
};