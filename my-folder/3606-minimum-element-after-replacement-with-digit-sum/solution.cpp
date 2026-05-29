class Solution {
public:
    int minElement(vector<int>& nums) {
        int res = INT_MAX;
        for (int i = 0; i < nums.size(); i++)
        {
            string s = to_string(nums[i]);
            int temp = 0;
            for (int j = 0; j < s.size(); j++)
            {
                temp += s[j] - '0';
            }
            res = min(res, temp);
        }
        return res;
    }
};
