public class Solution {
    public int MinEatingSpeed(int[] piles, int h)
    {
        int l = 1, r = (int)1e9 + 5;
        int res = 0;
        while(l <= r)
        {
            int mid = (l + r) >> 1;
            long cnt = 0;
            for(int i =0;i<piles.Length;++i)
                cnt += (piles[i] + mid - 1) / mid;
            if (cnt <= h)
            {
                res = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return res;
    }
}