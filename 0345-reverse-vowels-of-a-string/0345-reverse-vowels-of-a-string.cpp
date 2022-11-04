class Solution {
public:
    string reverseVowels(string s) {
        vector<char>v = {'a','e','i','o','u','A','E','I','O','U'};
        vector<char>v1;
        for(auto i : s)
        {
            if (find(v.begin(),v.end(),i) != v.end())
                v1.push_back(i);
        }
        
        reverse(v1.begin(),v1.end());
        int p = 0;
        for(int i = 0 ; i < s.size();++i)
        {
            if (find(v.begin(),v.end(),s[i]) != v.end() && !v1.empty())
                s[i] = v1[p++];
        }
        return s;
    }
};