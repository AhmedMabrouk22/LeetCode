class Solution {
public:
    string reverseWords(string s) {
        int n = s.size() - 1;
        string res="";
        for(int i = n ; i>=0;--i)
        {
            string str="";
            int j = i;
            while(j >= 0 && s[j] != ' ')
            {
                str = s[j] + str;
                --j;
            }
            
            if (str != "")
                res += str + " ";
            i = j;
        }
        res.pop_back();
         return res;
    }
   
};