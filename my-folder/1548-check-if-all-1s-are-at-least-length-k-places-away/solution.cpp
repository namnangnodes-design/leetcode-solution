class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int last = - 1 - k;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                if (i - last > k)
                {
                    last = i;
                }
                else return false;
            }
        }
        return true;
    }
};
