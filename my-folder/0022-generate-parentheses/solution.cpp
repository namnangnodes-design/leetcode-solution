class Solution {
public:
    vector<string> result;
    vector<int> leftPos;
    int mN;
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++)
        {
            char temp = s[i];
            if (temp == '(') st.push(temp);
            else
            {
                if (st.empty()) return false;
                st.pop();
            }
        }
        return st.empty();
    }
    void backtrack(int num, int index)
    {
        if (num == mN)
        {
            string s;
            for (int i = 0; i < leftPos.size(); i++)
            {
                if (leftPos[i] == 1)
                {
                    s.push_back('(');
                }
                else
                {
                    s.push_back(')');
                }
            }
            if (isValid(s))
            {
                result.push_back(s);
            }
        }
        for (int i = index + 1; i < leftPos.size() - 1; i++)
        {
            leftPos[i] = 1;
            backtrack(num + 1, i);
            leftPos[i] = 0;
        }
    }
    vector<string> generateParenthesis(int n) {
        result.clear();
        mN = n;
        for (int i = 0; i < 2 * n; i++)
        {
            leftPos.push_back(0);
        }
        leftPos[0] = 1;
        backtrack(1, 0);
        return result;
    }
};

