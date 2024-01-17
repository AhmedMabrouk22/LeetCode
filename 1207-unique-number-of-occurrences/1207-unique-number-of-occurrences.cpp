class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int>mp,frq;
        for(auto i : arr) ++frq[i];
        for(auto i : frq)
        {
            if (mp[i.second]) return false;
            ++mp[i.second];
        }
        return true;
    }
};