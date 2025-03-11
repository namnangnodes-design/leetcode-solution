class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        unordered_map<char, int> charMap;
        for (int i = 0; i < s.length(); i++)
        {
            if (charMap.find(s[i]) == charMap.end())
            {
                charMap[s[i]] = 1;
            }
            else
            {
                charMap[s[i]]++;
            }
        }
        for (int i = 0; i < t.length(); i++)
        {
            if (charMap.find(t[i]) == charMap.end())
            {
                //printf("%d", i);
                return false;
            }
            else
            {
                charMap[t[i]]--;
                if (charMap[t[i]] < 0)
                {
                    //printf("%d", i);
                    return false;
                }
            }
        }

        return true;
    }
};
