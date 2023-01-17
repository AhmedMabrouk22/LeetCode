class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int idx = 0;
        while(idx < n && s[idx] == ' ')
            ++idx;
        
        bool neg = false;
        if (s[idx] == '-')
        {
            ++idx;
            neg = true;
        }
        else if (s[idx] == '+')
            ++idx;
            
        long long res = 0;
        for(int i = idx ; i < n; ++i)
        {
            if (!isdigit(s[i]))
                break;
            
            res *= 10;
            res += (s[i] - '0');
            if (res >= INT_MAX)
                break;
            
        }
        
        res = (neg ? -res : res);
        if (res >= INT_MAX)
            return INT_MAX;
        else if (res <= INT_MIN)
            return INT_MIN;
        else 
            return res;
        
    }
};