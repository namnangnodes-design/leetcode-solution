class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n2 = nums2.size();
        stack<int> s;
        vector<int> right(n2, -1);
        unordered_map<int, int> map2;
        for (int i = 0; i < nums2.size(); i++)
        {
            map2[nums2[i]] = i;
            while(!s.empty() && nums2[i] > nums2[s.top()])
            {
                right[s.top()] = nums2[i];
                s.pop();
            }
            s.push(i);
        }
        for (int i = 0; i < nums1.size(); i++)
        {
            nums1[i] = right[map2[nums1[i]]];
        }
        return nums1;
    }
};
