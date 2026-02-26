class Solution {
public:
    int numSteps(string s) {
        int step = 0;
        while (s != "1")
        {
            int len = s.size();
            if (s[len - 1] == '0')
            {
                s.pop_back();
            }
            else
            {
                int index = len - 1;
                while (index > -1 && s[index] == '1')
                {
                    index--;
                }
                if (index == -1)
                {
                    step++;
                    string s1 = "1";
                    for (int i = 1; i < len; i++)
                    {
                        s1.push_back('0');
                    }
                    s = s1;
                }
                else
                {   s[index] = '1';
                    for (int i = index + 1; i < len; i++)
                    {
                        s[i] = '0';
                    }
                }
            }
            step++;
        }
        return step;
    }
};
