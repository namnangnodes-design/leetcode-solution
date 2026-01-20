int min(int a, int b)
{
    return a < b ? a : b;
}

int jump(int* nums, int numsSize) {
    int memo[10001];
    for (int i = 0; i < numsSize; i++)
    {
        memo[i] = 10001;
    }
    memo[0] = 0;
    int farest = 0;
    for (int i = 0; i < numsSize; i++)
    {
        for (int j = i; j <= i + nums[i] && j < numsSize; j++)
        {
            if (j <= farest) continue;
            farest = j;
            memo[j] = min(memo[i] + 1, memo[j]);
        }
    }
    return memo[numsSize - 1];
}
