int max(int a, int b)
{
    return a > b ? a : b;
}

int min(int a, int b)
{
    return a < b ? a : b;
}

int maxProfit(int* prices, int pricesSize) {
    int buy1 = INT_MIN;
    int sell1 = INT_MIN;
    int buy2 = INT_MIN;
    int sell2 = INT_MIN;
    for (int i = 0; i < pricesSize; i++)
    {
        buy1 = max(-prices[i], buy1);
        sell1 = max(sell1, prices[i] + buy1);
        buy2 = max(sell1 - prices[i], buy2);
        sell2 = max(sell2, prices[i] + buy2);
    }
    return sell2;
}
