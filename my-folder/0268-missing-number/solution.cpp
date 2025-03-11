
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_set<int> mSet;
        for (int i = 0; i <= nums.size(); i++)
        {
            mSet.insert(i);
        }
        for (int i = 0; i < nums.size(); i++)
        {
            mSet.erase(nums[i]);
        }
        int hi = 0;
        for (int m: mSet)
        {
            hi = m;
        }
        return hi;
    }
};
