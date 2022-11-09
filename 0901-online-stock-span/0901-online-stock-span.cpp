class StockSpanner {
public:
    StockSpanner() {
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    }
    stack<pair<int,int>> stack;
    int next(int price) {
        int ans = 1;
        while (!stack.empty() && stack.top().first <= price) {
            ans += stack.top().second;
            stack.pop();
        }
        
        stack.push({price, ans});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */