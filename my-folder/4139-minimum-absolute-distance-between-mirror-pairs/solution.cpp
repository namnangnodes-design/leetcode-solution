class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> mMap; // Store only the most recent index for each reversed value
        int n = nums.size();
        int res = 1000000;
        for (int i = 0; i < n; i++)
        {
            // Check if current number matches any previously stored reversed value
            auto it = mMap.find(nums[i]);
            if (it != mMap.end()) {
                res = min(res, i - it->second); // Only closest previous index matters for min distance
            }
            // Update map with current number's reverse, overwriting older index (keeps closest candidate)
            int r = reverseInt(nums[i]);
            mMap[r] = i;
        }
        return res == 1000000 ? -1 : res;
    }

    int reverseInt(int a)
    {
        string s = to_string(a);
        reverse(s.begin(), s.end());
        return stoi(s);
    }
};
