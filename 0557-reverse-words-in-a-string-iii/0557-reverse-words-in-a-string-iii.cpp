class Solution {
public:
    string reverseWords(string s) {
        string str = "";
        string res = "";
        for(auto i : s)
        {
            if (i != ' ')
                str += i;
            else 
            {
                reverse(str.begin(),str.end());
                res += str;
                res += ' ';
                str = "";
            }
        }
        reverse(str.begin(),str.end());
        res += str;
        return res;
    }
};