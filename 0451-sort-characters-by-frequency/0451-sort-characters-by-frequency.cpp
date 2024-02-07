class Solution {
public:
    string frequencySort(string s) {
        map<char,int>frq;
        for(auto i : s) ++frq[i];
        vector<pair<int,char>>v;
        for(auto i : frq) v.push_back({i.second,i.first});
        sort(v.rbegin(),v.rend());
        string res = "";
        for(auto i : v)
        {
            while(frq[i.second]--) res += i.second;
        }
        return res;
    }
};