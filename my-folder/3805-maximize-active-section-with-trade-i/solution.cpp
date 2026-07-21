class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        vector<pair<int, int>> ones;
        bool oning = true;
        int start = -1;
        int oneCount = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (oning)
            {
                if (s[i] == '0')
                {
                    ones.push_back({start, i - 1});
                    oning = false;
                }
            }
            else
            {
                if (s[i] == '1')
                {
                    start = i;
                    oning = true;
                }
            }
            if (s[i] == '1') 
            {
                oneCount++;
            }
        }
        if (oning) 
        {
            ones.push_back({start, s.size()});
        }
        else 
        {
            ones.push_back({s.size(), s.size()});
        }
        int res = 0;
        for (int i = 1; i < ones.size() - 1; i++)
        {
            res = max(ones[i].first - 1 - ones[i - 1].second + ones[i + 1].first - 1 - ones[i].second, res);
        }
        return res + oneCount;
    }
};
