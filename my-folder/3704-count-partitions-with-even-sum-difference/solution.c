int countPartitions(int* nums, int numsSize) {
    int prefix[100];
    prefix[0] = nums[0];
    int count = 0;
    for (int i = 1; i < numsSize; i++)
    {
        prefix[i] = prefix[i - 1] + nums[i];
    }
    for (int i = 0; i < numsSize - 1; i++)
    {
        if ((prefix[i] - prefix[numsSize - 1] - prefix[i]) % 2 == 0)
        {
            count++;
        }
    }
    return count;
}
