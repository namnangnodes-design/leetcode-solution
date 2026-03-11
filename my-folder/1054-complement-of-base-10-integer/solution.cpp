class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;
        if (n == 1) return 0;
        long long int prev = 0;
        long long int cur = 1;
        for (int i = 1; i < 30; i++)
        {
            prev = cur;
            cur += pow(2, i);
            if (n >= prev && n <= cur)
            {
                return cur - n;
            }
        }
        return 0;
    }
};
