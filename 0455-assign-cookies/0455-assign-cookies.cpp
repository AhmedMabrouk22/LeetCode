#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int res = 0;
        int ch = 0, co = 0;
        while (ch < g.size() && co < s.size())
        {
            if (g[ch] <= s[co])
            {
                ++res;
                ++ch;
                ++co;
            } 
            else ++co;
        }
        return res;
    }
};