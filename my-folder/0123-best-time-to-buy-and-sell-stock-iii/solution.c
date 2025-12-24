int maxProfit(int* prices, int pricesSize) {
    int res = 0;
    int min = prices[0];
    int profit = 0;
    int* left = (int*) malloc(pricesSize * sizeof(int));
    int* right = (int*) malloc(pricesSize * sizeof(int));
    for (int i = 0; i < pricesSize; i++)
    {
        if (prices[i] < min)
        {
            min = prices[i];
        }
        else if (prices[i] - min > profit)
        {
            profit = prices[i] - min;
        }
        left[i] = profit;
    }
    int max = 0;
    profit = 0;
    for (int i = pricesSize - 1; i > -1; i--)
    {
        if (max < prices[i])
        {
            max = prices[i];
        } 
        else if (profit < max - prices[i])
        {
            profit = max - prices[i];
        }
        right[i] = profit;
    }
    res = right[0] > left[pricesSize - 1] ? right[0] : left[pricesSize - 1];    
    for (int i = 0; i < pricesSize - 1; i++)
    {
        if (left[i] + right[i + 1] > res)
        {
            res = left[i] + right[i + 1];
        }
    }
    return res;
}
