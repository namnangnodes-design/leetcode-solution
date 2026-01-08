int max(int a, int b)
{
    return a > b ? a : b;
}

int maxProfit(int* prices, int pricesSize, int fee) {
    int* free = malloc(pricesSize * sizeof(int));
    int* hold = malloc(pricesSize * sizeof(int));
    int res = 0;
    for (int i = 0; i < pricesSize; i++)
    {
        free[i] = 0;
        hold[i] = -prices[0];
    }
    for (int i = 1; i < pricesSize; i++)
    {
        free[i] = max(hold[i - 1] + prices[i] - fee, free[i - 1]);
        hold[i] = max(free[i - 1] - prices[i], hold[i - 1]);
    }

    return free[pricesSize - 1];
}


