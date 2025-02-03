class Solution {
public:
    int countSegments(string s) {
        int result = 0;
        int n = s.length();
        for (int i = 0; i < n; ++i)
        {
            if (s[i] != ' ')
            {
                result++;
                while (s[i] != ' ' && i < n)
                {
                    i++;
                }
            }
        }
        return result;
    }
};
