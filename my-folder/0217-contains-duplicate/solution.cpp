class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> mSet;
        for (int i = 0; i < nums.size(); i++)
        {
            if (mSet.find(nums[i]) == mSet.end())
            {
                mSet.insert(nums[i]);  
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};
