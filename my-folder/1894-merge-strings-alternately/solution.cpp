class Solution {
public:
    std::string mergeAlternately(std::string word1, std::string word2) {
        std::string ret = "";
        int i = 0;
        while (i < word1.length() && i < word2.length()) {
            ret.push_back(word1.at(i));
            ret.push_back(word2.at(i));
            i++;
        }
        while (i < word1.length()) {
            ret.push_back(word1[i]);
            i++;
        }
        while (i < word2.length()) {
            ret.push_back(word2[i]);
            i++;
        }
        return ret;
    }
};
