class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> sumMap;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++)
        {
            if (sumMap.find(nums.at(i)) != sumMap.end())
            {
                result.push_back(sumMap[nums.at(i)]);
                result.push_back(i);
                return result;
            }
            sumMap[target - nums.at(i)] = i;
        }
        return result;
    }
};
