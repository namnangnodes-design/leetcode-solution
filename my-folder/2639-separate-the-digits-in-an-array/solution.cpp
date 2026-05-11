class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        for (int i = 0; i < n; i++)
        {
            string s = to_string(nums[i]);
            for (int j = 0; j < s.size(); j++)
            {
                res.push_back(s[j] - 48);
            }
        }
        return res;
    }
};
