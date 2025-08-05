
class Solution {
public:
    int maxScore = 0;
    int charArr[26];
    int index = 0;
    struct Word
    {
        string value;
        int score;
        int mChar[26];
    };

    unordered_map<int, Word> wordMap;
    void dfs(int curScore, int curIndex, const int curCharArr[]) {
        // Check if current character counts exceed available letters
        for (int i = 0; i < 26; i++) {
            if (curCharArr[i] > charArr[i]) {
                return;
            }
        }
        // Update maxScore if current score is higher
        if (curScore > maxScore) {
            maxScore = curScore;
        }
        // If all words are processed, return
        if (curIndex == wordMap.size()) {
            return;
        }
        // Recursive call without including the current word
        dfs(curScore, curIndex + 1, curCharArr);
        // Create a copy of curCharArr to avoid modifying the original array
        int tempCharArr[26];
        std::copy(curCharArr, curCharArr + 26, tempCharArr);
        // Include the current word and update character counts and score
        Word tWord = wordMap[curIndex];
        for (int i = 0; i < 26; i++) {
            tempCharArr[i] += tWord.mChar[i];
        }
        dfs(curScore + tWord.score, curIndex + 1, tempCharArr);
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        for (int i = 0; i < 26; i++)
        {
            charArr[i] = 0;
        }
        for (int i = 0; i < letters.size(); i++)
        {
            charArr[letters[i] - 97]++;
        }
        for (int i = 0; i < words.size(); i++)
        {
            int wordArr[26];
            for (int j = 0; j < 26; j++)
            {
                wordArr[j] = 0;
            }
            int mscore = 0;
            bool can = true;
            for (int j = 0; j < words[i].size(); j++)
            {
                wordArr[words[i][j] - 97]++;
                if (wordArr[words[i][j] - 97] > charArr[words[i][j] - 97])
                {
                    can = false;
                    break;
                }
                mscore += score[words[i][j] - 97];
            }
            if (!can)
            {
                continue;
            }
            Word a;
            a.score = mscore;
            a.value = words[i];
            for (int j = 0; j < 26; j++)
            {
                a.mChar[j] = wordArr[j];
            }
            wordMap[index] = a;
            index++;
        }
        int temp[26];
        for (int i = 0; i < 26; i++)
        {
            temp[i] = 0;
        }
        dfs(0, 0, temp);
        return maxScore;
    }
};
