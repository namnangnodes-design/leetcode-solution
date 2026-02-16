class Solution {
public:
    int reverseBits(int n) {
        string bin;
        while (n > 0)
        {
            bin.push_back(n % 2 == 0 ? '0' : '1');
            n /= 2;
        }
        while (bin.size() < 32) bin.push_back('0');
        int res = 0;
        
        for (int i = bin.size() - 1; i > -1; i--)
        {
            res += pow(2, (bin.size() - i - 1)) * (bin[i] - 48);
        }
        return res;
    }
};
