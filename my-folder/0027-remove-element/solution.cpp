class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int index = 0;
        int size = nums.size();
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == val)
            {
                size--;
                continue;
            }
            nums[index] = nums[i];
            index++;
        }
        return size;
    }
};
