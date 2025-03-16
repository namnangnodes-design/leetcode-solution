class Solution {
public:
    int maxSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int result = 0, mMax = nums[0]; // mMax starts as the smallest element
        int prev = INT_MIN; // Track last unique number

        for (int num : nums) {
            mMax = max(mMax, num);
            if (num > 0 && num != prev) {
                result += num;
            }
            prev = num;
        }
        
        return (result > 0) ? result : mMax;
    }
};

