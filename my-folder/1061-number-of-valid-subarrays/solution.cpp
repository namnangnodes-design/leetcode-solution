class Solution {
public:
    int validSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> mS;
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            while (!mS.empty() && nums[mS.back()] > nums[i])
            {
                res += i - mS.back();
                mS.pop_back();
            }
            mS.push_back(i);
        }
        for (int i = 0; i < mS.size(); i++)
        {
            res += n - mS[i];
        }
        return res;
    }
};
