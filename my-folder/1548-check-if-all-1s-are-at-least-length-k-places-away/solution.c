bool kLengthApart(int* nums, int numsSize, int k) {
    int last = - 1 - k;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == 1)
        {
            if (i - last > k)
            {
                last = i;
            }
            else return false;
        }
    }
    return true;
}
