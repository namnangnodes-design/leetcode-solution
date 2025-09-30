class Solution {
public:
    vector<int> factor;
    void makeFactors(int l)
    {
        factor.clear();
        for (int i = 1; i <= l / 2; i++)
        {
            if (l % i == 0) factor.push_back(i);
        }
    }

    bool repeatedSubstringPattern(string s) {
        if (s.length() <= 1) return false;
        makeFactors(s.length());
        for (int i = 0; i < factor.size(); i++)
        {
            string sub = s.substr(0, factor[i]);
            string temp = sub;
            int r = s.length() / factor[i] - 1;
            while (r > 0)
            {
                temp += sub;
                r--;
            }
            if (temp == s) return true;
        }

        return false;
    }
};
