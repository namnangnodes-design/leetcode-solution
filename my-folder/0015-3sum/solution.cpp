class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        set<vector<int>> setJ;
        for (int i = 0; i < nums.size() - 2; i++)
        {
            int j = i + 1;
            int k = nums.size() - 1;
            //printf("nums[i] %d nums[j] %d nums[k] %d \n", nums[i], nums[j], nums[k]);
            while (j < k)
            {
                int sum = nums[j] + nums[k];
                if (sum < -nums[i])
                {
                    j++;
                }
                else if (sum > -nums[i])
                {
                    k--;
                }
                else 
                {
                    setJ.insert({nums[i], nums[j], nums[k]});
                    j++;
                }
            }
        }
        for (auto x: setJ)
        {
            res.push_back(x);
        }
        return res;
    }
};
