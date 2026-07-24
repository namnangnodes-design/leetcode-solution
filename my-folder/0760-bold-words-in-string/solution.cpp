class Solution {
public:
    string boldWords(vector<string>& words, string s) {
        int n = s.size();
        vector<bool> marks(n, false);
        for (const auto &w: words)
        {
            int pos = 0;
            while ((pos = s.find(w, pos)) != string::npos)
            {
                for (int i = 0; i < w.size(); i++)
                {
                    marks[pos + i] = true;
                }
                pos++;
            }
        }

        bool inM = false;
        string res;
        for (int i = 0; i < n; i++)
        {
            if (inM)
            {
                if (!marks[i])
                {
                    res.append("</b>");
                    inM = false;
                }
            }
            else
            {
                if (marks[i])
                {
                    res.append("<b>");
                    inM = true;
                }
            }
            res.push_back(s[i]);
        }
        if (inM)
        {
            res.append("</b>");
        }
        return res;
    }
};
