class Solution {
public:
    bool winnerOfGame(string colors) {
        int cnt = 1 , a = 0 , b = 0;
        int n = colors.size();
        for(int i = 1 ; i < n; ++i) 
        {
            if (colors[i] == colors[i-1]) ++cnt;
            else 
            {
                if (cnt >= 3)
                {
                    if (colors[i - 1] == 'A') a += cnt - 3 + 1;
                    else b += cnt - 3 + 1;
                }
                cnt = 1;
            }
        }
        if (cnt >= 3) 
        {
            if (colors[n - 1] == 'A') a += cnt - 3 + 1;
            else b += cnt - 3 + 1;
        }
        return a > b;
    }
};