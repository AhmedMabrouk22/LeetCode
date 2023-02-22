public class Solution {
    public int ShipWithinDays(int[] weights, int days)
        {
            int l = 0, r = (int)1e9;
            //Array.Sort(weights);
            while(l<r)
            {
                int mid = (l + r) >> 1;
                int temp = 0;
                int cnt = 0;
                for(int i = 0; i < weights.Length; ++i)
                {
                    if (temp + weights[i] <= mid)
                        temp += weights[i];
                    else if (weights[i] <= mid)
                    {
                        ++cnt;
                        temp = weights[i];
                    }
                    else 
                    {
                        cnt = days;
                        break;
                    }
                }

                if (cnt < days)
                    r = mid;
                else
                    l = mid + 1;

            }

            return r;
        }
}