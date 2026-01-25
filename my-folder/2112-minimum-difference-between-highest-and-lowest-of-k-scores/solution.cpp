class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if (k == 1) return 0;
        sort(nums.begin(), nums.end());
        int res = nums[k - 1] - nums[0];
        for (int i = k; i < nums.size(); i++)
        {
            if (nums[i] - nums[i - k + 1] < res) res = nums[i] - nums[i - k + 1];
        }
        return res;
    }
};
