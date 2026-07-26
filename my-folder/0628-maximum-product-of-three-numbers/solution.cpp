class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        if (nums.size() == 3)
        {
            return nums[0] * nums[1] * nums[2];
        }
        vector<int> neg;
        vector<int> pos;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < 0)
            {
                neg.push_back(nums[i]);
            }
            else
            {
                pos.push_back(nums[i]);
            }
        }
        sort(pos.begin(), pos.end(), greater<int>());
        sort(neg.begin(), neg.end());
        int candidate1 = INT_MIN;
        if (pos.size() > 2)
        {
            candidate1 = pos[0] * pos[1] * pos[2];
        }
        int candidate2 = INT_MIN;
        if (pos.size() > 0 && neg.size() > 1)
        {
            candidate2 = pos[0] * neg[0] * neg[1];
        }
        int candidate3 = INT_MIN;
        if (neg.size() > 2)
        {
            candidate3 = neg[neg.size() - 1] * neg[neg.size() - 2] * neg[neg.size() - 3];
        }
        int candidate4 = INT_MIN;
        if (pos.size() > 0 && neg.size() > 1)
        {
            candidate4 = pos[pos.size() - 1] * neg[neg.size() - 1] * neg[neg.size() - 2];
        }
        return max(max(candidate1, candidate2), max(candidate3, candidate4));
    }
};
