class Solution {
public:
    bool isDivisor(string str1, string str2)
    {
        int len1 = str1.length();
        int len2 = str2.length();
        string temp;
        for (int i = 0; i < len1 / len2; i++)
        {
            temp.append(str2);
        }
        if (str1.compare(temp) == 0)
        {
            return true;
        }
        return false;
    }
    string gcdOfStrings(string str1, string str2) {
        string result = "";
        int len1 = str1.length();
        int len2 = str2.length();
        if (len1 >= len2)
        {
            for (int i = len2; i > 0; i--)
            {
                if (len1 % i != 0 || len2 % i != 0)
                {
                    continue;
                }
                for (int j = 0; j <= len2 - j; j++)
                {
                    string temp = str2.substr(j, i);
                    //cout << "temp " << temp << endl;
                    if (isDivisor(str1, temp) && isDivisor(str2, temp))
                    {
                        return temp;
                    }
                }
            }
        }
        else
        {
            for (int i = len1; i > 0; i--)
            {
                if (len1 % i != 0 || len2 % i != 0)
                {
                    continue;
                }
                for (int j = 0; j <= len1 - j; j++)
                {
                    string temp = str1.substr(j, i);
                    //cout << "temp " << temp << endl;
                    if (isDivisor(str2, temp) && isDivisor(str1, temp))
                    {
                        return temp;
                    }
                }
            }
        }
        return result;
    }
};
