class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0;
        int curMax = nums[0];
        for (int i = 0; i + k < n; i++)
            {
                curMax = max(nums[i], curMax);
                res = max(res, curMax + nums[i + k]);
            }
        return res;
    }
};
