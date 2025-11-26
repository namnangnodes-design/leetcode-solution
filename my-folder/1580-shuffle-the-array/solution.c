

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shuffle(int* nums, int numsSize, int n, int* returnSize){
    *returnSize = n * 2;
    int* ans = (int*)malloc(n * 2 * sizeof(int));
    for (int i = 0, j = 0; i < n; i++, j += 2)
    {
        ans[j] = nums[i];
        ans[j + 1] = nums[i + n]; 
    }
    return ans;
}
