class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]); 
        vector<int> rob(n, 0);
        rob[0] = nums[0];
        rob[1] = nums[1];
        rob[2] = max(nums[0] + nums[2], nums[1]);
        for (int i = 3; i < n; i++)
        {
            rob[i] = max(max(rob[i - 2] + nums[i], rob[i - 1]), rob[i - 3] + nums[i]);
        }
        return max(rob[n - 1], rob[n - 2]);
    }
};
