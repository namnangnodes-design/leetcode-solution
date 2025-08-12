class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mMin = 1001, mMax = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < mMin)
            {
                mMin = nums[i];
            }
            if (nums[i] > mMax)
            {
                mMax = nums[i];
            }
        }
        int mMod = 1000;
        while (mMin != 1)
        {
            mMod = mMax % mMin;
            if (mMod == 0)
            {
                return mMin;
            }
            mMax = mMin;
            mMin = mMod;
        }
        return mMin;
    }
};
