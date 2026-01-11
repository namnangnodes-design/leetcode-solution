int max(int a, int b)

{

    return a > b ? a : b;

}

int deleteAndEarn(int* nums, int numsSize) {

    int sums[10001];

    int res[10001];

    for (int i = 0; i < 10001; i++)

    {

        sums[i] = 0;

        res[i] = 0;

    }

    int maxNum = INT_MIN;

    for (int i = 0; i < numsSize; i++)

    {

        sums[nums[i]] += nums[i];

        maxNum = max(nums[i], maxNum);

    }

    res[0] = sums[0];

    res[1] = max(sums[0], sums[1]);

    for (int i = 2; i <= maxNum; i++)

    {

        res[i] = max(res[i - 2] + sums[i], res[i - 1]);

    }

    return max(res[maxNum - 1], res[maxNum]);

}
