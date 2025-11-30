/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    bool check[100001] = {false};
    *returnSize = numsSize;
    for (int i = 0; i < numsSize; i++)
    {
        if (!check[nums[i]])
        {
            check[nums[i]] = true;
            (*returnSize)--;
        }
    }
    int* ans = (int*) malloc(*returnSize * sizeof(int));
    int index = 0;
    for (int i = 1; i <= numsSize; i++)
    {
        if (!check[i]) {
            ans[index] = i;
            index++;
        }
    }
    return ans;
}
