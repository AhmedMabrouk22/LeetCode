class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        for(int i = 0 ; i < strs[0].size();++i)
        {
            char cur = strs[0][i];
            bool f = true;
            for(int j = 1 ; j < strs.size() ;++j)
            {
               if ((strs[j].size() >= i + 1 && strs[j][i] != cur) || strs[j].size() < i + 1)
               {
                    f = false;
                   break;
               }
            }
            if (f)
                res += cur;
            else 
                break;
        }
        return res;
	}
};