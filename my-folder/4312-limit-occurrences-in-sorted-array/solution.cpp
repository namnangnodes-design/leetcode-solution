class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        vector<int> res;
        int cur = nums[0];
        int count = 1;
        res.push_back(cur);
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != cur)
            {
                cur = nums[i];
                count = 1;
            }
            else
            {
                count++;
            }
            if (count <= k)
            {
                res.push_back(cur);
            }
                
        }
        return res;
    }
};
