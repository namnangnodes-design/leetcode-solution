class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int st = students.size();
        int sa = sandwiches.size();
        queue<int> sQ;
        stack<int> sS;
        for (int i = 0; i < st; i++)
        {
            sQ.push(students[i]);
        }
        for (int i = sa - 1; i > -1; i--)
        {
            sS.push(sandwiches[i]);
        }
        while (!sS.empty())
        {
            int cur = sQ.size();
            bool have = false;
            for (int i = 0; i < cur; i++)
            {
                if (sS.top() == sQ.front())
                {
                    sQ.pop();
                    sS.pop();
                    have = true;
                }
                else
                {
                    sQ.push(sQ.front());
                    sQ.pop();
                }
            }
            if (!have)
            {
                break;
            }
        }
        return sQ.size();
    }
};
