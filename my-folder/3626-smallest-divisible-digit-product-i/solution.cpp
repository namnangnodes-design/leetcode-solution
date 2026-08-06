class Solution {
public:
    int smallestNumber(int n, int t) {
        int res = n;
        while (1)
        {
            string s = to_string(res);
            int product = 1;
            for (int i = 0; i < s.size(); i++)
            {
                product *= s[i] - '0';
            }
            if (product % t == 0)
            {
                return res;
            }
            res++;
        }
        return res;
    }
};
