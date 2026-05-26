class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<bool> check1(26, false);
        vector<bool> check2(26, false);
        int res = 0;
        int n = word.size();
        for (int i = 0; i < n; i++)
        {
            if (word[i] > 'Z')
            {
                check2[word[i] - 'a'] = true;
            }
            else
            {
                check1[word[i] - 'A'] = true;   
            }
        }
        for (int i = 0; i < 26; i++)
        {
            if (check1[i] && check2[i])
            {
                res++;
            }
        }
        return res;
    }
};
