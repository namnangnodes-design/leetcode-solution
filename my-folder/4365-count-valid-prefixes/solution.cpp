class Solution {
public:
    int countValidPrefixes(string s) {
        int n = s.size();
        vector<int> count1(n, 0);
        count1[0] = s[0] - '0';
        int res = 1;
        for (int i = 1; i < n; i++)
            {
                count1[i] = count1[i - 1] + (s[i] == '1');
                res += (abs(i + 1 - count1[i] * 2) <= 1);
                // printf("i = %d count1[i] = %d 0 = %d res = %d \n", i, count1[i], abs(i + 1 - count1[i] * 2) , res);
            }
        return res;
    }
};
