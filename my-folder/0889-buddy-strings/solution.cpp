class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int diff = 0;
        int arr[26];
        if (s.length() != goal.length()) return false;
        if (s.length() == 2 && s.compare(goal) == 0 && s[0] != s[1]) return false;
        bool mustCmp = true;
        for (int i = 0; i < s.size(); i++)
        {
            arr[s[i] - 'a']++;
            if (mustCmp && arr[s[i] - 'a'] > 1)
            {
                mustCmp = false;
            }
        }
        if (mustCmp && s.compare(goal) == 0) return false;
        for (int i = 0; i < s.size(); i++)
        {
            arr[goal[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++)
        {
            if (arr[i] != 0)
            {
                return false;
            }
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != goal[i])
            {
                diff++;
            }
        }
        if (diff < 3) return true;
        return false;
    }
};
