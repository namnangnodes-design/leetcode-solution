class Solution {
public:
int countPalindromicSubsequence(string s) {
        unordered_map<char, int> left;
        for (int i = 0; i < s.size(); i++)
        {
            if (left.find(s[i]) == left.end())
            {
                left[s[i]] = i;
            }
        }
        unordered_map<char, int> right;
        for (int i = s.size() - 1; i > -1; i--)
        {
            if (right.find(s[i]) == right.end())
            {
                right[s[i]] = i;
            }
        }
        unordered_set<string> palindromes;
        for (char i = 'a'; i <= 'z'; i++)
        {
            if (left.find(i) != left.end() && right.find(i) != right.end() && left[i] + 1 < right[i])
            {
                for (int j = left[i] + 1; j < right[i]; j++)
                {
                    string palindrome = "";
                    palindrome += i;
                    palindrome += s[j];
                    palindrome += i;
                    palindromes.insert(palindrome);
                }
            }
        }
        return palindromes.size();
    }
};
