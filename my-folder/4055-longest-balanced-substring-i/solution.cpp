class Solution {
public:
    int longestBalanced(string s) {
        size_t len = 0;

        for (size_t i = 0; i < s.size(); i++) {
            unordered_map<char, int> charMap;

            for (size_t j = i; j < s.size(); j++) {
                charMap[s[j]]++;
                bool canUse = true;
                int val = charMap[s[j]];
                for (auto c: charMap)
                {
                    if (c.second != val)
                    {
                        canUse = false;
                        break;
                    }
                }
                if (canUse) 
                {
                    len = std::max(len, j - i + 1);
                }
            }
        }

        return len;
    }
};
