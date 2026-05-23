class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        bool desed = false;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] < nums[i - 1])
            {
                if (desed) 
                {
                    return false;
                }
                else
                {
                    desed = true;
                }
            }
        }
        if (desed && nums[0] < nums[n - 1])
        {
            return false;
        }
        return true;
    }
};
