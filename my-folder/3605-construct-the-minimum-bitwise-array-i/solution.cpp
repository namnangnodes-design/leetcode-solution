class Solution {
public:
    int res[1001];
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            if (res[nums[i]] != 0) 
            {
                ans.push_back(res[nums[i]]);
                continue;
            }
            bool canFind = false;
            for (int j = nums[i] / 2; j < nums[i]; j++)
            {
                if ((j | (j + 1)) == nums[i])
                {
                    canFind = true;
                    ans.push_back(j);
                    res[nums[i]] = j;
                    break;
                }
            }
            if (!canFind) ans.push_back(-1);
        }
        return ans;
    }
};
