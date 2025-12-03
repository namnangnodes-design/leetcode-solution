int removeElement(int* nums, int numsSize, int val) {
    int index = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == val) 
        {
            continue;
        }
        nums[index++] = nums[i];
    }
    return index;
}
