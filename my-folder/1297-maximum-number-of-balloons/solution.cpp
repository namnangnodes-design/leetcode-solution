class Solution {
public:

    int maxNumberOfBalloons(string text) {
        int countB = 0;
        int countA = 0;
        int countL = 0;
        int countO = 0;
        int countN = 0;
        for (int i = 0; i < text.size(); i++)
        {
            switch(text[i])
            {
                case 'b':
                    countB++;
                    break;
                case 'a':
                    countA++;
                    break;
                case 'l':
                    countL++;
                    break;
                case 'o':
                    countO++;
                    break;
                case 'n':
                    countN++;
                    break;
                defaults:
                    break;
            }
        }
        int res = 10000;
        res = min(countB, res);
        res = min(countA, res);
        res = min(countL / 2, res);
        res = min(countO / 2, res);
        res = min(countN, res);
        return res;
    }
};
