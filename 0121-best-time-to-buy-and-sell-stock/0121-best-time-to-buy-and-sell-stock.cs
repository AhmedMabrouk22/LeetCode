public class Solution {
    public int MaxProfit(int[] prices) {
        var mn = prices[0];
        var mx = 0;
        foreach(var i in prices)
        {
            mn = Math.Min(mn, i);
            mx = Math.Max(mx, i - mn);
        }
        return mx;
    }
}