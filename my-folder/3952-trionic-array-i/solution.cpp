class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        if (nums[0] >= nums[1]) return false;
        int state = 1;
        for (int i = 2; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1]) return false;
            if (state == 1)
            {
                if (nums[i] < nums[i - 1]) state = 2;
            }
            else if (state == 2)
            {
                if (nums[i] > nums[i - 1]) state = 3;
            }
            else if (state == 3)
            {
                if (nums[i] < nums[i - 1]) return false;
            }
        }
        return state == 3;
    }
};
