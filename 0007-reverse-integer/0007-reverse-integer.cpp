class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while(x)
        {
            int a = x % 10;
            x /= 10;
            if (1LL*res*10 + x > INT_MAX || 1LL*res*10 + x < INT_MIN)
                return 0;
            res = res * 10 + a;
            
           
        }
        return res;
    }
};