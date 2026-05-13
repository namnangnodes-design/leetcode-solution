class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sums = {0};
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            sums.push_back(sums[i] + nums[i]);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (sums[j] - sums[i] == k)
                {
                    res++;
                }
            }
        }
        return res;
    }
};
