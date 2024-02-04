class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";
        multiset<char>ch;
        for(auto i : t) ch.insert(i);
        unordered_map<char,int>frq1,frq2;
        for(auto i : t) ++frq1[i];
        int cnt = 0;
        vector<pair<int,int>>v;
        int i = 0 , r = 0;
        int n = s.size();
        int m = ch.size();
        for( ; i < n; ++i)
        {
            while(r < n && cnt < m)
            {
                if (ch.find(s[r]) != ch.end() && frq2[s[r]] < frq1[s[r]])
                    ++cnt;
                ++frq2[s[r]];

                
                ++r;     
            }
            
            if (cnt == m)
                v.push_back({i,r});
            
            if (ch.find(s[i]) != ch.end() && frq2[s[i]] == frq1[s[i]])
                --cnt;
            --frq2[s[i]];
        }
        
               
        if (!v.size()) return "";
        int idx = 0, mi = v[0].second - v[0].first;
        for(int i = 1 ; i < v.size() ; ++i)
        {
            int x = v[i].second - v[i].first;
            if (x < mi)
            {
                idx = i;
                mi = x;
            }
        }
        
        string res = "";
        for(int i = v[idx].first ; i < v[idx].second ; ++i) res += s[i];
        
        return res;
    }
};