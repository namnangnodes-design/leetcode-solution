class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int n = nums.size();
        int l = 0;
        int cur = 1;
        int res = 0;
        for (int r = 0; r < n; r++)
        {
            cur *= nums[r];
            while (cur >= k && l <= r)
            {
                cur /= nums[l++];
            }
            if (cur < k)
            {
                res += r - l + 1;
            }
        }
        return res;
    }
};
