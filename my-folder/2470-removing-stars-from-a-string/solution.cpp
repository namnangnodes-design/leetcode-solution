class Solution {
public:
    string removeStars(string s) {
            string result = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '*' && result.length() != 0)
        {
            result.pop_back();
        }
        else if (s[i] != '*')
        {
            result.push_back(s[i]);
        }
    }
    return result;
    }
};
