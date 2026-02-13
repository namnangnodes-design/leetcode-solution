class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            unordered_set<int> odd;
            unordered_set<int> even;
            for (int j = i ; j < nums.size(); j++)
            {
                if (nums[j] % 2 == 0)
                {
                    odd.insert(nums[j]);
                }
                else
                {
                    even.insert(nums[j]);
                }
                if (odd.size() == even.size())
                {
                    res = max(res, j - i + 1);
                }
            }
        }
        return res;
    }
};
