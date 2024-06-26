class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    vector<int> numsLeft;
    for (int i = 0; i < m; i++)
    {
        numsLeft.push_back(nums1[i]);
    }
    int indexLeft = 0;
    int indexRight = 0;
    int index = 0;
    while (indexLeft < m && indexRight < n)
    {
        if (indexRight == n || numsLeft[indexLeft] <= nums2[indexRight])
        {
            nums1[index] = numsLeft[indexLeft];
            index++;
            indexLeft++;
        }
        else
        {
            nums1[index] = nums2[indexRight];
            index++;
            indexRight++;
        }
    }
            for (int i = indexLeft; i < m; i++)
        {
            nums1[index] = numsLeft[i];
            index++;
        }
    for (int i = indexRight; i < n; i++)
    {
        nums1[index] = nums2[i];
        index++;
    }
    return;
    }
};
