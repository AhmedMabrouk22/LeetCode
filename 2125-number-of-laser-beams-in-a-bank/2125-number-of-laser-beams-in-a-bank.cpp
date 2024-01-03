#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int frq[500];
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        int m = bank[0].size();
        for(int i = 0 ; i < n ; ++i)
        {
            for(int j = 0 ; j < m ; ++j)
            {
                if (bank[i][j] == '1') ++frq[i];
            }
        }

        int res = 0;
        int p = frq[0];
        for(int i = 1 ; i < n ; ++i)
        {
            res += frq[i] * p;
            if (frq[i])
                p = frq[i];
        }
        return res;
    }
};