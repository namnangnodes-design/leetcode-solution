class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farest = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (i > farest) return false;
            farest = max(farest, i + nums[i]);
            if (farest >= nums.size() - 1) return true;
        }
        return false;
    }
};
