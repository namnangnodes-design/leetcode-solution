class Solution {
public:
    char findKthBit(int n, int k) {
        // while (k - 1 < pow(2, n - 1))
        // {
        //     n--;
        // }
        int cur = 1;
        string s = "0";
        while (cur < n || s.length() < k - 1)
        {
            string si = s;
            for (int i = 0, k = si.size() - 1; i < si.size(); i++, k--)
            {
                si[k] = s[i] == '1' ? '0' : '1';
            }
            s.push_back('1');
            s.append(si);
            cur++;
        }
        return s[k - 1];
    }
};
