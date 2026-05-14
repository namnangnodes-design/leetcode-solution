class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> countMap;
        int maxNum = 0;
        for (int i = 0; i < n; i++)
        {
            countMap[nums[i]]++;
            maxNum = max(maxNum, nums[i]);
        }

        for (int i = 1; i < maxNum; i++)
        {
            if (countMap[i] != 1)
            {
                return false;
            }
        }

        return countMap[maxNum] == 2;
    }
};
