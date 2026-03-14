class Solution {
public:
    int n;
    vector<string> mRes;
    string getHappyString(int n, int k) {
        this->n = n;
        mRes.clear();
        backtracking("");
        if (mRes.size() < k) return "";
        return mRes[k - 1];
    }
    void backtracking(string cur)
    {
        if (cur.size() == n)
        {
            mRes.push_back(cur);
            return;
        }
        for (char i = 'a'; i <= 'c'; i++)
        {
            if (cur.size() > 0 && cur[cur.size() - 1] == i)
            {
                continue;
            }
            cur.push_back(i);
            backtracking(cur);
            cur.pop_back();
        }
    }
};
