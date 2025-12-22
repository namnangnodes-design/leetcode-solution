int maxProfit(int* prices, int pricesSize) {
    if (pricesSize == 0) return 0;
    int minPrice = INT_MAX;
    int maxProfit = 0;
    for (int i = 0; i < pricesSize; i++)
    {
        if (minPrice > prices[i])
        {
            minPrice = prices[i];
        }
        else if (maxProfit < prices[i] - minPrice)
        {
            maxProfit = prices[i] - minPrice;
        }
    }
    return maxProfit;
}
