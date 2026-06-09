class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long mi = INT64_MAX;
        long long ma = INT64_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            mi = min(mi, (long long) nums[i]);
            ma = max(ma, (long long) nums[i]);
        }
        return (ma - mi) * k;
    }
};
