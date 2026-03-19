class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        res.push_back(1);
        for (int i = 1; i < n; i++)
        {
            res.push_back(res[i - 1] * nums[i - 1]);
        }
        int cur = 1;
        for (int i = n - 2; i > -1; i--)
        {
            cur *= nums[i + 1]; 
            res[i] *= cur;
        }
        return res;
    }
};
