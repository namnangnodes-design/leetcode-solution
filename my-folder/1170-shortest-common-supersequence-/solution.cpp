class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int s1 = str1.size();
        int s2 = str2.size();
        vector<vector<int>> memo(s1 + 1, vector<int> (s2 + 1)); 
        for (int i = 0; i <= s1; i++)
        {
            memo[i][0] = 0;
        }
        for (int i = 0; i <= s2; i++)
        {
            memo[0][i] = 0;
        }
        string lcs;
        for (int i = 1; i <= s1; i++)
        {
            for (int j = 1; j <= s2; j++)
            {
                if (str1[i - 1] == str2[j - 1])
                {
                    memo[i][j] = memo[i - 1][j - 1] + 1;
                }
                else
                {
                    memo[i][j] = max(memo[i - 1][j], memo[i][j - 1]);
                }
            }
        }

        int i = s1;
        int j = s2;
        string ans;
        ans.reserve(s1 + s2);
        while (i > 0 && j > 0)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                ans.push_back(str1[i - 1]);
                i--;
                j--;
            }
            else if (memo[i - 1][j] >= memo[i][j - 1])
            {
                ans.push_back(str1[i - 1]);
                i--;
            }
            else
            {
                ans.push_back(str2[j - 1]);
                j--;
            }
        }

        while (i > 0)
        {
            ans.push_back(str1[i - 1]);
            i--;
        }

        while (j > 0)
        {
            ans.push_back(str2[j - 1]);
            j--;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
