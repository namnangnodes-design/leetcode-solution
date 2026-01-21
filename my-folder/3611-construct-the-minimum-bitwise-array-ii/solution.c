/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* minBitwiseArray(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    for (int i = 0; i < numsSize; i++)
    {
        int res = -1;
        int checkBit = 1;
        while ((nums[i] & checkBit) != 0)
        {
            res = nums[i] - checkBit;
            checkBit <<= 1;
        }
        nums[i] = res;
    }
    return nums;
}
