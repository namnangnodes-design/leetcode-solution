int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int res = 0;
    int cur = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == 1) 
        {
            cur++;
            if (cur > res) res = cur;
        }
        else
        {
            cur = 0;
        }
    }
    return res;
}
