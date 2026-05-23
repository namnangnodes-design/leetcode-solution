class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int r;
        int n = nums.size();
        int count0 = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (nums[i] == 0)
            {
                count0++;
            }
        }
        int countNoSwap = 0;
        for (int i = n - 1; i >= n - count0; i--)
        {
            if (nums[i] == 0)
            {
                countNoSwap++;
            }
        }
        return count0 - countNoSwap;
    }
};
