class StockSpanner {
public:
    stack<pair<int, int>> mS;
    StockSpanner() {
    }
    
    int next(int price) {
        int res = 1;
        while (!mS.empty() && mS.top().first <= price)
        {
            res += mS.top().second;
            mS.pop();
        }
        mS.push({price, res});
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
