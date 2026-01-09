int max(int a, int b)
{
    return a > b ? a : b;
}

int rob(int* nums, int numsSize) {
    if (numsSize == 1) return nums[0];
    int* money = malloc(numsSize * sizeof(int));
    money[0] = nums[0];
    money[1] = max(nums[0], nums[1]);
    for (int i = 2; i < numsSize; i++)
    {
        money[i] = max(money[i - 1], money[i - 2] + nums[i]); 
    }
    return money[numsSize -1];
}
