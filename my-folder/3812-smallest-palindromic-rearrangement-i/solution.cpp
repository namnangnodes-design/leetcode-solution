class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> cs(26, 0);
        for (int i = 0; i < s.size(); i++)
        {
            cs[s[i] - 'a']++;
        }
        string res;
        bool f = false;
        char alone;
        for (int i = 0; i < 26; i++)
        {
            if (cs[i] % 2 == 0)
            {
                for (int j = 0; j < cs[i] / 2; j++)
                {
                    res.push_back(i + 'a');
                }
            }
            else
            {
                for (int j = 0; j < cs[i] / 2; j++)
                {
                    res.push_back(i + 'a');
                }
                f = true;
                alone = i + 'a';
            }
        }
        string r(res.rbegin(), res.rend());
        if (f) res.push_back(alone);
        res.append(r);
        return res;
    }
};
