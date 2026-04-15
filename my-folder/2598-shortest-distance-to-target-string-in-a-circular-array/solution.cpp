class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int res = 101;
        int n = words.size();
        for (int i = 0; i < words.size(); i++)
        {
            if (words[i] == target)
            {
                res = min(min(res, abs(n - i + startIndex)), min(abs(i - startIndex), abs(n + i - startIndex))); 
            }
        }
        if (res == 101)
        {
            return -1;
        }
        return res;
    }
};
