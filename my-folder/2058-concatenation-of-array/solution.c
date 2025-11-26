/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getConcatenation(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize * 2;
    int *ans = (int*)malloc(*returnSize * sizeof(int));
    for (int i = 0; i < numsSize; i++)
    {
        ans[i] = nums[i];
        ans[i + numsSize] = nums[i];
    }
    // for (int i = 0; i < numsSize * 2; i++)
    // {
    //     printf("ans[%d] = %d\n", i, ans[i]);
    // }
    return ans;
}
