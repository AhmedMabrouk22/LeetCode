class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) return false;
       vector<int>a,b;
        map<char,int>mp,mp2;
        for(auto i : word1) ++mp[i];
        for(auto i : mp) a.push_back(i.second);
        
        for(auto i : word2)
        {
            if (!mp[i]) return false;
            ++mp2[i];
        }
        for(auto i : mp2) b.push_back(i.second);
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        for(int i = 0 ; i < a.size(); ++i)
        {
            if (a[i] != b[i]) return false;
        }
        return true;
    }
};