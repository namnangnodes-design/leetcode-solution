class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        if (m > n) return false;
        vector<int> v1(26, 0);
        vector<int> v2(26, 0);
        int hash1 = 0;
        int hash2 = 0;
        for (int i = 0; i < m; i++)
        {
            v1[s1[i] - 97]++;
            hash1 += s1[i];
            v2[s2[i] - 97]++;
            hash2 += s2[i];
        }
        if (hash1 == hash2)
        {
            bool equal = true;
            for (int i = 0; i < 26; i++)
            {
                if (v1[i] != v2[i]) 
                {
                    equal = false;
                    break;
                }
            }
                if (equal) 
                {
                    return true;
                }
        }
        for (int i = m; i < n; i++)
        {
            hash2 = hash2 - s2[i - m] + s2[i];
            v2[s2[i - m] - 97]--;
            v2[s2[i] - 97]++;
            if (hash1 == hash2)
            {
                bool equal = true;
                for (int j = 0; j < 26; j++)
                {
                    if (v1[j] != v2[j]) 
                    {
                        equal = false;
                        break;
                    }
                }
                if (equal) 
                {
                    return true;
                }
            }
        }
        return false;
    }
};
