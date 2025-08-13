class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int minDiff = 3 * pow(10, 4);
        int sumTemp;
        int result;

        for (int i = 0; i < nums.size() - 2; i++)
        {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right)
            {
                sumTemp = nums[left] + nums[i] + nums[right];
                if (minDiff > abs(target - sumTemp))
                {
                    minDiff = abs(target - sumTemp);
                    result = sumTemp;
                }
                if (sumTemp < target)
                {
                    left++;
                }
                else if (sumTemp > target)
                {
                    right--;
                }
                else
                {
                    return target;
                }
            }

        }
        return result;
    }
};
