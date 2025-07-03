class Solution {
public:
    char kthCharacter(int k) {
        string res = "a";
        while (res.length() < k)
        {
            string app = res;
            for (int i = 0; i < res.length(); i++)
            {
                if (res[i] == 'z')
                {
                    res[i] = 'a';
                    continue;
                }
                app[i]++;
            }
            res.append(app);
        }
        return res[k - 1];
    }
};
