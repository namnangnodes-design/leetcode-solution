/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* ans = (int*)malloc(*returnSize * sizeof(int));
    int count[501];
    int prefix[501];
    for (int i = 0; i < numsSize; i++)
    {
        count[nums[i]]++;
    }
    // for (int i = 0; i <= 8; i++)
    // {
    //     printf("i %d count %d \n", i, count[i]);
    // }
    for (int i = 1; i <= 500; i++)
    {
        prefix[i] = prefix[i - 1] + count[i - 1];
    }
    // for (int i = 0; i <= 8; i++)
    // {
    //     printf("i %d prefix %d \n", i, prefix[i]);
    // }
    for (int i = 0; i < numsSize; i++)
    {
        ans[i] = prefix[nums[i]];
    }
    return ans;
}
