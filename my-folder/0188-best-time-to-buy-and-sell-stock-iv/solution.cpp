class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<int> buy;
        vector<int> sell;
        for (int i = 0; i <= k; i++)
        {
            buy.push_back(INT_MIN + 1001);
            sell.push_back(0);
        }
        for (int price: prices)
        {
            for (int i = 1; i <= k; i++)
            {
                buy[i] = max(buy[i], sell[i - 1] - price);
                sell[i] = max(sell[i], buy[i] + price); 
            }
        }
        return sell[k];
    }
};
