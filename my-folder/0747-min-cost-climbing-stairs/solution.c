int min(int a, int b)
{
    return a < b ? a : b;
}

int minCostClimbingStairs(int* cost, int costSize) {
    int sumEven = cost[0];
    int sumOdd = cost[1];
    bool even = true;
    for (int i = 2; i < costSize; i++)
    {
        if (even)
        {
            sumEven = min(sumEven + cost[i], sumOdd + cost[i]);
        }
        else
        {
            sumOdd = min(sumEven + cost[i], sumOdd + cost[i]);
        }
        even = !even;
    }
    return min(sumEven, sumOdd);
}
