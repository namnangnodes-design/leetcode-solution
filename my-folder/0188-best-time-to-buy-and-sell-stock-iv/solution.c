int max(int a, int b)
{
    return a >= b ? a : b;
}

int min(int a, int b)
{
    return a < b ? a : b;
}

int maxProfit(int k, int* prices, int pricesSize) {
    int* bought = malloc((k + 1) * sizeof(int));
    int* sold = malloc((k + 1) * sizeof(int));
    for (int i = 0; i <= k; i++)
    {
        bought[i] = INT_MIN;
        sold[i] = 0;
    }
    for (int i = 0; i < pricesSize; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            bought[j] = max(bought[j], sold[j - 1] - prices[i]);
            sold[j] = max(sold[j], bought[j] + prices[i]);
        }
    }
    return sold[k];
}
