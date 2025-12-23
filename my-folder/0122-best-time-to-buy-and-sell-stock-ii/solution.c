int maxProfit(int* prices, int pricesSize) {
    int index = 0;
    int result = 0;
    while (index < pricesSize - 1)
    {
        if (prices[index] < prices[index + 1])
        {
            result += prices[index + 1] - prices[index];
        }
        index++;
    }
    return result;
}
