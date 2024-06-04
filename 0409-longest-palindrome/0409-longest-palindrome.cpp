class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int>frq;
        for(auto i : s) ++frq[i];
        int len = 0;
        bool odd = false;
        for(auto i : frq)
        {
            if (i.second % 2 == 0) len += i.second;
            else 
            {
                odd = true;
                len += i.second - 1;
            }
        }
        
        return len + (odd ? 1 : 0);
    }
};