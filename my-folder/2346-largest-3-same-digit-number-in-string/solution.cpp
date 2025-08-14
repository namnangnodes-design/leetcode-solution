class Solution {
public:
    string largestGoodInteger(string num) {
        string result;
        char mDigit = ' ' ;
        for (int i = 0; i < num.size() - 2; i++)
        {
            if (num[i] == num[i + 1] && num[i + 1] == num[i + 2] && num[i] > mDigit)
            {
                mDigit = num[i];
            }
        }
        if (mDigit == ' ')
        {
            return "";
        }
        result.push_back(mDigit);
        result.push_back(mDigit);
        result.push_back(mDigit);
        return result;
    }
};
