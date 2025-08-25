class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 3)
        {
            return nums.size();
        }
        int index = 2;
        for (int i = 2; i < nums.size(); i++)
        {
            if (nums[i] == nums[index - 2]) continue;
            nums[index] = nums[i];
            index++;
        }
        return index;
    }
};
