class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(101, 0);
        int minNum = 101;
        int maxNum = 0;
        for (int i = 0; i < n; i++)
        {
            count[nums[i]]++;
            minNum = min(nums[i], minNum);
            maxNum = max(nums[i], maxNum);
        }
        vector<int> res;
        for (int i = minNum; i <= maxNum; i++)
        {
            if (count[i] == 0) res.push_back(i);
        }
        return res;
        
    }
};
