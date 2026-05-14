class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<char> charSt;
        stack<int> countSt;
        int n = s.size();
        string res;

        for (int i = 0; i < n; i++)
        {
            if (!charSt.empty() && charSt.top() == s[i])
            {
                countSt.top()++;
                if (countSt.top() == k)
                {
                    charSt.pop();
                    countSt.pop();
                }
            }
            else
            {
                charSt.push(s[i]);
                countSt.push(1);
            }
        }
        while (!charSt.empty())
        {
            for (int i = 0; i < countSt.top(); i++)
            {
                res.push_back(charSt.top());        
            }
            charSt.pop();
            countSt.pop();
        }
        for (int i = 0, j = res.size() - 1; i < j; i++, j--)
        {
            char temp = res[i];
            res[i] = res[j];
            res[j] = temp; 
        }
        return res;
    }
};
