class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        if (nums.size() == 1) return 0;
        map<int, int> countMap;
        int maxNum = INT_MIN;
        int res = INT_MAX;
        for (int i = 0; i < nums.size(); i++)
        {
            countMap[nums[i]]++;
            if (nums[i] > maxNum) maxNum = nums[i]; 
        }
        int preSum = 0;
        int postSum = 0;
        map<int, int> preSumMap;
        map<int, int> postSumMap;
        for (auto i: countMap)
        {
            preSumMap[i.first] = preSum;
            preSum += i.second;
        }

        for (auto i: countMap)
        {
            if ((double)maxNum / i.first <= k) 
            {
                postSumMap[i.first] = 0;
            }
            else
            {
                int upperBound = countMap.upper_bound(i.first * k)->first;
                postSumMap[i.first] = preSum - preSumMap[upperBound];
            }
        }
        
        for (auto i: countMap)
        {
            if (preSumMap[i.first] + postSumMap[i.first] < res) res = preSumMap[i.first] + postSumMap[i.first];
        }

        return res;
    }
};
