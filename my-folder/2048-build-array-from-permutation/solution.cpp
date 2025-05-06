class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> result;
        int n = nums.size();
        result.resize(n);
        for (int i = 0; i < n; i++)
        {
            result[i] = nums[nums[i]];
        }
        return result;
    }
};
