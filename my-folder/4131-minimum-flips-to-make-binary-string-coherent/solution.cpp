class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        if (n < 3 || s == "101") return 0;
        int count1 = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1') count1++;
        }
        int count0 = n - count1;
        if (s[0] == '1' && s[n - 1] == '1') count1--;
        return max(min(count1 - 1, count0), 0);
    }
};
