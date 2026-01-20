int max(int a, int b)
{
    return a > b ? a : b;
}

bool canJump(int* nums, int numsSize) {
    int farest = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (i > farest) return false;
        farest = max(farest, nums[i] + i);
    }
    return farest >= numsSize - 1;
}
