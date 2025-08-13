class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() == 1)
        {
            return s;
        }
        if (s.size() == 2)
        {
            if (s[0] == s[1])
            {
                return s;
            }
        }
        string result;
        result.push_back(s[0]);
        int maxSize = 1;
        for (int i = 0; i < s.size(); i++)
        {
            string temp;
            if (i > 0 && s[i - 1] == s[i + 1])
            {
                temp.push_back(s[i - 1]);
                temp.push_back(s[i]);
                temp.push_back(s[i + 1]);
                if (temp.size() > result.size())
                {
                    maxSize = temp.size();
                    result = temp;
                }
                int left = i - 2;
                int right = i + 2;
                while (left >= 0 && right < s.size())
                {
                    if (s[right] != s[left])
                    {
                        break;
                    }
                    string t;
                    t.push_back(s[left]);
                    t.append(temp);
                    t.push_back(s[right]);
                    temp = t;
                    if (temp.size() > result.size())
                    {                            
                        result = temp;
                        maxSize = temp.size();
                    }
                    right++;
                    left--;
                }
            }
            temp = "";
            if (s[i + 1] == s[i])
            {
                temp.push_back(s[i]);
                temp.push_back(s[i + 1]);
                if (temp.size() > result.size())
                {
                    maxSize = temp.size();
                    result = temp;
                }
                int left = i - 1;
                int right = i + 2;
                while (left >= 0 && right < s.size())
                {
                    if (s[right] != s[left])
                    {
                        break;
                    }
                    string t;
                    t.push_back(s[left]);
                    t.append(temp);
                    t.push_back(s[right]);
                    temp = t;
                    if (temp.size() > result.size())
                    {                            
                        result = temp;
                        maxSize = temp.size();
                    }
                    right++;
                    left--;
                }
            }
        }
        return result;
    }
};
