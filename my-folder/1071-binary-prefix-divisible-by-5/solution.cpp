class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> res;
        int mod = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            mod = mod * 2 + nums[i];
            mod %= 5;
            res.push_back(mod == 0);
        }
        return res;
    }
};
