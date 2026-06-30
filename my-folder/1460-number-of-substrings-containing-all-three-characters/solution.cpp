class Solution {
public:
    int numberOfSubstrings(string s) {
        int res = 0;
        int n = s.size();
        if (n < 3)
        {
            return 0;
        }
        vector<int> cCount(3, 0);
        int i = 0;
        while (i < n)
        {
            cCount[s[i] - 'a']++;
            if (cCount[0] >= 1 && cCount[1] >= 1 && cCount[2] >= 1)
            {
                res += n - i;
                break;
            }
            i++;
        }
        for (int j = 0; j < n; j++)
        {
            if (i == n)
            {
                break;
            }
            cCount[s[j] - 'a']--;
            if (cCount[0] >= 1 && cCount[1] >= 1 && cCount[2] >= 1)
            {
                res += n - i;
            }
            else
            {
                while (i < n - 1)
                {
                    i++;
                    cCount[s[i] - 'a']++;
                    if (cCount[0] >= 1 && cCount[1] >= 1 && cCount[2] >= 1)
                    {
                        res += n - i;
                        break;
                    }
                }
            }
        }
        return res;
    }
};
