class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        int n = nums.size();
        nums.insert(nums.end(), nums.begin(), nums.end());
        vector<int> res(n, -1);
        for (int i = 0; i < 2 * n; i++)
        {
            while (!s.empty())
            {
                int l = s.top();
                if (nums[l] < nums[i])
                {
                    res[l % n] = nums[i];
                    s.pop(); 
                }
                else
                {
                    break;
                }
            }
            s.push(i);
        }
        return res;
    }
};
