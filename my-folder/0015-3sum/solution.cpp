class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int target = 0;
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        vector<vector<int>> output;
        for (int i = 1; i < nums.size() - 1; i++){
            int j = i - 1;
            int k = i + 1;
            while (j >= 0 && k <= nums.size() - 1) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target) {
                    s.insert({nums[j], nums[i], nums[k]});
                    k++;
                    j--;
                } else if (sum < target) {
                    k++;
                } else {
                    j--;
                }
            }
        }
        for(auto triplets : s)
            output.push_back(triplets);
        return output;
    }
};
