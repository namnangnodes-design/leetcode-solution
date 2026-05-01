class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int res = -2147483648;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
        }
        vector<int> sums;
        for (int i = 0; i < n; i++)
        {
            sums.push_back(sum - nums[i]);
        }
        int proSum = 0;
        for (int i = 0; i < n; i++)
        {
            proSum += nums[i] * i;
        }
        res = max(res, proSum);
        for (int i = n - 1; i > 0; i--)
        {
            proSum += sums[i] - (n - 1) * nums[i];
            res = max(res, proSum);
        }
        return res;
    }
};
