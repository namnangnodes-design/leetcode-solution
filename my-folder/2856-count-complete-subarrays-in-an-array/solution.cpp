class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> fullSet(nums.begin(), nums.end());
        int fullCount = fullSet.size();
        int result = 0;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            unordered_set<int> tempSet;
            for (int j = i; j < n; ++j) {
                tempSet.insert(nums[j]);
                if (tempSet.size() == fullCount) {
                    result++;
                }
            }
        }

        return result;
    }
};

