int memo[301][100001];
int ns[100001];
int ms[301];
int n;
int m;

int max(int a, int b)
{
    return a > b ? a : b;
}

int dp(int action, int left)
{
    if (action == m)
    {
        return 0;
    }
    if (memo[action][left] == 0)
    {
        memo[action][left] = max(dp(action + 1, left + 1) + ms[action] * ns[left], dp(action + 1, left) + ms[action] * ns[n - 1 - action + left]);
    }
    return memo[action][left];
}

int maximumScore(int* nums, int numsSize, int* multipliers, int multipliersSize) {
    for (int i = 0; i < numsSize; i++)
    {
        ns[i] = nums[i];
    }
    for (int i = 0; i < multipliersSize; i++)
    {
        ms[i] = multipliers[i];
    }
    for (int i = 0; i < multipliersSize; i++)
    {
        for (int j = 0; j < multipliersSize; j++)
        {
            memo[i][j] = 0;
        }
    }
    m = multipliersSize;
    n = numsSize;
    return dp(0, 0);
}
