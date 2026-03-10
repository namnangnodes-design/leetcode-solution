class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;
        int res = 0;
        sort(nums.begin(), nums.end());
        for (int i = n - 1; i > 1; i--)
        {
            int j = i - 1;
            int k = 0;
            while (k < j)
            {
                if (nums[k] + nums[j] > nums[i])
                {
                    res += j - k;
                    j--;
                }
                else
                {
                    k++;
                }
            }
        }
        return res;
    }
};
