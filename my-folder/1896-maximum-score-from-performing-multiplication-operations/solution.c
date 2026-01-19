int memo[302][302];

int max(int a, int b)
{
    return a > b ? a : b;
}

int maximumScore(int* nums, int numsSize, int* multipliers, int multipliersSize) {
    for (int i = 0; i <= multipliersSize; i++)
    {
        for (int j = 0; j <= multipliersSize; j++)
        {
            memo[i][j] = 0;
        }
    }
    for (int i = multipliersSize - 1; i >= 0; i--)
    {
        for (int left = i; left >= 0; left--)
        {
            int right = numsSize - 1 + left - i;
            memo[i][left] = max(memo[i + 1][left + 1] + multipliers[i] * nums[left], memo[i + 1][left] + multipliers[i] * nums[right]);
        }
    }
        
    return memo[0][0];
}
