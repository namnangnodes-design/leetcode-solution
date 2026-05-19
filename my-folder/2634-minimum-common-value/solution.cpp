class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> nums1Set;
        for (int i = 0; i < nums1.size(); i++)
        {
            nums1Set.insert(nums1[i]);

        }
        int res = -1;
        for (int i = 0; i < nums2.size(); i++)
        {
            if (nums1Set.find(nums2[i]) != nums1Set.end())
            {
                if (res == -1 || nums2[i] < res)
                {
                    res = nums2[i];
                }
            }
        }
        return res;
    }
};
