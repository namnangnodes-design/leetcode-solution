class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;
        int cur = 0;
        int res = 0;
        while (r < nums.size())
        {
            cur += nums[r] == 0 ? 1 : 0;
            if (cur <= k)
            {
                res = max(res, r - l + 1);
                r++;
            }
            else
            {
                cur -= nums[l] == 0 ? 1 : 0;
                l++;
                r++;
            }
        }
        return res;
    }
};
