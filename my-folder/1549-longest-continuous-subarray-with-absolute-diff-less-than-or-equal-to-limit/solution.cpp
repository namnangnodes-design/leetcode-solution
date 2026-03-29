class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> ascDq;
        deque<int> desDq;
        int l = 0;
        int res = 0;
        for (int r = 0; r < nums.size(); r++)
        {
            while (!ascDq.empty() && nums[ascDq.back()] >= nums[r])
            {
                ascDq.pop_back();
            }
            ascDq.push_back(r);
            while (!desDq.empty() && nums[desDq.back()] <= nums[r])
            {
                desDq.pop_back();
            }
            desDq.push_back(r);
            while (nums[desDq.front()] - nums[ascDq.front()] > limit) {
                if (ascDq.front() == l) ascDq.pop_front();
                if (desDq.front() == l) desDq.pop_front();
                l++;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};
