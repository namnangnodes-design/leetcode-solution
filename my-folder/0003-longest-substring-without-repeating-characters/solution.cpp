class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charMap;
        int maxLength = 0;
        int tempLength = 0;
        int start = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (charMap.find(s[i]) != charMap.end())
            {
                tempLength = tempLength - charMap[s[i]] - 1 + start;
                for (int j = start; j < charMap[s[i]]; j++)
                {
                    charMap.erase(s[j]);
                }
                start = charMap[s[i]] + 1;
            }
            charMap[s[i]] = i;
            if (++tempLength > maxLength)
            {
                maxLength = tempLength;
            }
        }
        return maxLength;
    }
};
