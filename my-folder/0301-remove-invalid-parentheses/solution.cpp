class Solution {
public:
    unordered_set<string> mRes;
    string mS;

    vector<string> removeInvalidParentheses(string s) {
        mS = s;
        mRes.clear();
        int lR = 0;
        int rR = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(') lR++;
            if (s[i] == ')')
            {
                if (lR > 0) lR--;
                else rR++;
            }
        }
        string cur = "";
        backtrack(0, 0, 0, lR, rR, cur);
        vector<string> res;
        for (string i: mRes)
        {
            res.push_back(i);
        }
        return res;
    }

    void backtrack(int cI, int lC, int rC, int lR, int rR, string& cur)
    {
        if (cI == mS.size())
        {
            if (lR == 0 && rR == 0)
            {
                mRes.insert(cur);
            }
            return;
        }
        char c = mS[cI];
        if (c == '(')
        {
            backtrack(cI + 1, lC, rC, lR - 1, rR, cur);
        }
        else if (c == ')')
        {
            backtrack(cI + 1, lC, rC, lR, rR - 1, cur);
        }
        cur.push_back(c);
        if (c != '(' && c != ')')
        {
            backtrack(cI + 1, lC, rC, lR, rR, cur);
        }
        else if (c == '(')
        {
            backtrack(cI + 1, lC + 1, rC, lR, rR, cur);
        }
        else if (rC < lC)
        {
            backtrack(cI + 1, lC, rC + 1, lR, rR, cur);
        }
        cur.pop_back();
    }
};
