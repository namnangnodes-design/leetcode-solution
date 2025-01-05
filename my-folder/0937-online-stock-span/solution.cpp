class StockSpanner {
public:
    vector<int> stock;
    StockSpanner() {
        stock.clear();
    }

    int next(int price) {
        stock.push_back(price);
        if (stock.size() == 1)
        {
            return 1;
        }
        int span = 1;
        for (int i = stock.size() - 2; i >= 0; i--)
        {
            if (stock.at(i) > price)
            {
                break;
            }
            span++;
        }
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
