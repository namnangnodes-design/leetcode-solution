class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int b = INT_MAX;
        int c = INT_MAX;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < b)
            {
                c = b;
                b = nums[i];
            }
            else if (nums[i] < c)
            {
                c = nums[i];
            }
        }
        return nums[0] + b + c;
    }
};
