/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findErrorNums(int* nums, int numsSize, int* returnSize) {
    *returnSize = 2;
    int* ans = (int*)malloc(*returnSize * sizeof(int));
    bool hihi[10001];
    for (int i = 0; i < numsSize; i++)
    {
        if (hihi[nums[i]]) 
        {
            ans[0] = nums[i];
        }
        else
        {
            hihi[nums[i]] = true;
        }
    }
    for (int i = 1; i <= numsSize; i++)
    {
        if (!hihi[i])
        {
            ans[1] = i;
            break;
        }
    }
    return ans;
}
