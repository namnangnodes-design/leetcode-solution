class NumArray {
public:
    vector<int> mVec;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        mVec.resize(n + 1);
        mVec[0] = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            mVec[i + 1] = mVec[i] + nums[i];
        }
    }

    int sumRange(int left, int right) {
        if (left == 0) return mVec[right + 1];
        return mVec[right + 1] - mVec[left];
    }
};
