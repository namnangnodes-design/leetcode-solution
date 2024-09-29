class Solution {
public:
    int rob(vector<int>& nums) {
        int houseCount = nums.size();
        if (houseCount == 1)
        {
            return nums[0];
        }
        if (houseCount < 3)
        {
            return max(nums[0], nums[1]);
        }
        int* dp = new int[houseCount];
        dp[0] = nums[0];
        dp[1] = nums[1];
        dp[2] = dp[0] + nums[2];
        for (int i = 3; i < houseCount; i++)
        {
            dp[i] = max( dp[i - 2] + nums[i], dp[i - 3] + nums[i]);
        }
        
        return max(dp[houseCount - 1], dp[houseCount - 2]);
    }
};
