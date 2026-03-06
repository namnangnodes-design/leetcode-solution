class Solution {
public:
    bool checkOnesSegment(string s) {
        bool inString = true;
        int count = 1;
        for (int i = 1; i < s.size(); i++)
        {
            if (inString) 
            {
                if (s[i] == '0') 
                {
                    inString = false;
                }
            }
            else
            {
                if (s[i] == '1')
                {
                    count++;
                    inString = true;
                    if (count > 1) return false;
                }
            }
        }
        return count <= 1;
    }
};
