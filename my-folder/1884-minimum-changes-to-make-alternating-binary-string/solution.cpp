class Solution {
public:
    int minOperations(string s) {
        int even0 = 0;
        int odd0 = 0;
        int even1 = 0;
        int odd1 = 0;
        for (int i = 0; i < s.size(); i += 2)
        {
            if (s[i] == '1')
            {
                even1++;
            }
            else
            {
                even0++;
            }
        }
        for (int i = 1; i < s.size(); i += 2)
        {
            if (s[i] == '1')
            {
                odd1++;
            }
            else
            {
                odd0++;
            }
        }
        return min(even0 + odd1, even1 + odd0);
    }
};
