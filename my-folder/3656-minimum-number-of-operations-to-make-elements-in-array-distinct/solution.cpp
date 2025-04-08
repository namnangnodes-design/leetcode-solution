class Solution {
public:
    vector<int> mVec;
    int minimumOperations(vector<int>& nums) {
        mVec.clear();
        for (int i = 0; i < nums.size(); i++)
        {
            mVec.push_back(nums[i]);
        }
        int count = 0;
        int i = 0;
        bool done = isDistinct(i);
        while (!done && i < nums.size())
        {
            count++;
            i += 3;
            done = isDistinct(i);
        }
        return count;
    }
    bool isDistinct(int index)
    {
        int arr[101] = {};
        for (int i = index; i < mVec.size(); i++)
        {
            arr[mVec[i]]++;
            if (arr[mVec[i]] == 2)
            {
                return false;
            }
        }
        return true;
    }
};
