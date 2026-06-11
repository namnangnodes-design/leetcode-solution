class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1)
        {
            return false;
        }

        int n = nums.size();
        int target = sum / 2;
        vector<vector<bool>> memo(n, vector<bool>(target + 1, false));
        for (int i = 0; i < n; i++) {
            memo[i][0] = true;
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= target; j++)
            {
                memo[i][j] = memo[i - 1][j];
                if (j >= nums[i])
                {
                    memo[i][j] = memo[i][j] || memo[i - 1][j - nums[i]];
                }
            }
        }

        return memo[n - 1][target];

    }
};
