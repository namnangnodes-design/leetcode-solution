class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int minSum = 50001;
        int minIndex = -1;
        bool decreasing  = true;
        int ans = 0;
        while (decreasing)
        {
            minSum = 50001;
            minIndex = -1;
            decreasing  = false;
            for (int i = 1; i < nums.size(); i++)
            {
                if (minSum > nums[i - 1] + nums[i])
                {
                    minSum = nums[i - 1] + nums[i];
                    minIndex = i - 1;
                }
                if (nums[i - 1] > nums[i])
                {
                    decreasing = true; 
                }
            }
            if (!decreasing) break;
            nums[minIndex] = nums[minIndex] + nums[minIndex + 1];
            nums.erase(nums.begin() + minIndex + 1);
            ans++;
        }
        return ans;
    }
};
