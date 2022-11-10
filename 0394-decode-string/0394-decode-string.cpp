class Solution {
public:
    string decodeString(string s) {
        stack<char>st;
        for(auto i : s)
        {
            if (i != ']')
                st.push(i);
            else 
            {
                string str = "";
                while(st.top() != '[')
                {
                    str = st.top() + str;
                    st.pop();
                }
                st.pop();
                string k = "";
                while(!st.empty() && isdigit(st.top()))
                {
                    k = st.top() + k;
                    st.pop();
                }
                int num = stoi(k);
                for(int i = 0 ; i < num;++i)
                    for(int j = 0 ; j < str.size();++j)
                        st.push(str[j]);
            }
        }
        
        string res = "";
        while(!st.empty())
        {
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};