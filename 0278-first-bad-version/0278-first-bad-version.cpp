// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long l = 0 , r = n;
        long long res = 1e12;
        while(l <= r)
        {
            long long mid = (l+r) >> 1;
            if (isBadVersion(mid))
            {
                res = min(res, mid);
                r = mid - 1;
            }
            else 
                l = mid + 1;
        }
        return res;
    }
};