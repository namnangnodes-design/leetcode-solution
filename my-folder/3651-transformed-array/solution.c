/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* constructTransformedArray(int* nums, int n, int* returnSize) {
    *returnSize = n;
    int* res = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        res[i] = nums[((i + nums[i]) % n + n) % n];
    }
    return res;
}
