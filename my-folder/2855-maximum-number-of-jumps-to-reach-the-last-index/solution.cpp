class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> res(n, -1);
        res[0] = 0;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (res[j] != -1 && abs(nums[i] - nums[j]) <= target )
                {
                    res[i] = max(res[i], res[j] + 1);
                }
            }
        }
        return res[n - 1];
    }
};
