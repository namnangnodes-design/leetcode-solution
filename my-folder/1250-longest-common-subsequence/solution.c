int dp[1002][1002];

int longestCommonSubsequence(char* text1, char* text2) {
    for (int i = 0; text1[i] != 0; i++)
    {
        dp[i][0] = 0; 
    }
    for (int i = 0; text2[i] != 0; i++)
    {
        dp[0][i] = 0; 
    }
    int i = 1;
    int j = 1;
    while (text1[i - 1] != 0)
    {
        j = 1;
        while (text2[j - 1] != 0)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];
            }
            j++;
        }
        i++;
    }
    return dp[i - 1][j - 1];
}
