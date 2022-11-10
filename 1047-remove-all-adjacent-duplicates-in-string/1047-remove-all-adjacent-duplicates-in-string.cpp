class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        for(auto i : s)
        {
            if (st.empty() || st.top() != i)
                st.push(i);
            else
                while(!st.empty() && st.top() == i)
                    st.pop();
        }
        
        string res = "";
        while(!st.empty())
        {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};