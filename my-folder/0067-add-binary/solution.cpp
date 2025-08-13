class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int carry = 0;
        int i = 0;
        string result;
        while (i < a.size() && i < b.size())
        {
            int r = a[i] + b[i] + carry - '0' - '0';
            if (r == 3)
            {
                result.push_back('1');
                carry = 1;
            }
            else if (r == 2)
            {
                result.push_back('0');
                carry = 1;
            }
            else
            {
                result.push_back(r + '0');
                carry = 0;
            }
            i++;
        }
        //cout << "buoc 1 " << result << " ";
        while (i < a.size())
        {
            int r = a[i] + carry - '0';
            if (r == 3)
            {
                result.push_back('1');
                carry = 1;
            }
            else if (r == 2)
            {
                result.push_back('0');
                carry = 1;
            }
            else
            {
                result.push_back(r + '0');
                carry = 0;
            }
            i++;
        }
        //cout << "buoc 2 " << result << " ";
        while (i < b.size())
        {
            int r = b[i] + carry - '0';
            if (r == 3)
            {
                result.push_back('1');
                carry = 1;
            }
            else if (r == 2)
            {
                result.push_back('0');
                carry = 1;
            }
            else
            {
                result.push_back(r + '0');
                carry = 0;
            }
            i++;
        }
        //cout << "buoc 3 " << result << " ";
        if (carry) result.push_back('1');
        reverse(result.begin(), result.end());
        return result;
    }
};
