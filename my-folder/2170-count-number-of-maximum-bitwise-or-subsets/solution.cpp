class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int maxOR = 0, count = 0;

        for (int num : nums) {
            maxOR |= num;
        }

        for (int mask = 1; mask < (1 << n); mask++)
        {
            int curOR = 0;
            for (int i = 0; i < n; i++)
            {
                if (mask & (1 << i))
                {
                    curOR |= nums[i];
                }
            }
            if (curOR == maxOR)
            {
                count++;
            }
        }

        return count;
    }
};
