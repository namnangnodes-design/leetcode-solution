class Solution {
public:
    char findTheDifference(string s, string t) {
        int sumT = 0;
        int sumS = 0;
        for (int i = 0; i < s.size(); i++)
        {
            sumT += t[i];
            sumS += s[i];
        }
        sumT += t[t.size() - 1];
        return sumT - sumS;
    }
};
