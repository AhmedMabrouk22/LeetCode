class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int x = prices.size();
		vector<int>prf(x + 5), suf(x + 5);
		prf[0] = prices[0];
		suf[x - 1] = prices[x - 1];
        
		for (int i = 1; i < x; ++i)
			prf[i] = min(prf[i - 1], prices[i]);
        
        
		for (int i = x - 2; i >= 0; --i)
			suf[i] = max(suf[i + 1], prices[i]);
        
        
		int res = 0;
		for (int i = 0; i < x; ++i)
            res = max(res, suf[i] - prf[i]);

		return res;
        
    }
};