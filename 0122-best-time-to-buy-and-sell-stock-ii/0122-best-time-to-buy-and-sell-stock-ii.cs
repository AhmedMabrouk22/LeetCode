public class Solution {
    public int MaxProfit(int[] prices) {
        var res = 0;
        for(int i = 1 ; i < prices.Length; ++i)
        {
            if (prices[i] > prices[i-1])
                res += prices[i] - prices[i-1];
        }
        return res;
    }
}