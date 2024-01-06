class Solution {
public:
    int myAtoi(string s) {
        long int result = 0;
        bool negativeSign = false;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ' ')
            {
                continue;
            }
            else if (s[i] == '-' || s[i] == '+')
            {
                negativeSign = s[i] == '-' ? true : false;
                if (s[i + 1] < '0' || s[i + 1] > '9')
                {
                    return negativeSign ? (result * -1) : result;
                }
            }
            else if (s[i] >= '0' && s[i] <= '9')
            {
                if (result > pow(2, 31) / 10 && negativeSign)
                {
                    return -pow(2, 31);
                }
                else if (result > (pow(2, 31) - 1) / 10 && !negativeSign)
                {
                    return pow(2, 31) - 1;
                }
                
                else {
                    result *= 10;
                    if (result == 2147483640)
                    {
                        if (s[i] > '8' && negativeSign)
                        {
                            return -pow(2, 31);
                        }
                        else if (s[i] > '7' && !negativeSign)
                        {
                            return pow(2, 31) - 1;
                        }
                    }
                    
                    result += (s[i] - 48);
                    
                }
                if (s[i + 1] < '0' || s[i + 1] > '9')
                {
                    return negativeSign ? (result * -1) : result;
                }
            }
            else
            {
                return result;
            }
        }
        return negativeSign ? (result * -1) : result;
    }
};
