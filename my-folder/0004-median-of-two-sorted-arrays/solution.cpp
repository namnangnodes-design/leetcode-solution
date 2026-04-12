class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int a = nums1.size();
        int b = nums2.size();
        if (a > b)
        {
            return findMedianSortedArrays(nums2, nums1);
        }
        int l = 0;
        int r = a;
        int half = (a + b + 1) / 2;
        while (l <= r)
        {
            int i1 = l + (r - l) / 2;
            int i2 = half - i1;
            int l1 = i1 > 0 ? nums1[i1 - 1] : INT_MIN;
            int r1 = i1 < a ? nums1[i1] : INT_MAX;
            int l2 = i2 > 0 ? nums2[i2 - 1] : INT_MIN;
            int r2 = i2 < b ? nums2[i2] : INT_MAX;
            if (l1 <= r2 && l2 <= r1)
            {
                return (a + b) % 2 ? max(l1, l2) : ((max(l1, l2) + min(r1, r2)) / 2.0); 
            }
            else if (l1 > r2)
            {
                r = i1 - 1;
            }
            else 
            {
                l = i1 + 1;
            }
        }
        return -1;
    }
};
