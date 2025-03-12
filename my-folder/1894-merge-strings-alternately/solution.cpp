class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int s1 = word1.size();
        int s2 = word2.size();

        string s;
        s.reserve(s1 + s2);  // Preallocate memory to avoid reallocation overhead

        int i = 0, j = 0;
        while (i < s1 || j < s2) {
            if (i < s1) s.push_back(word1[i++]);  // Use push_back instead of +=
            if (j < s2) s.push_back(word2[j++]);  
        }
        return s;
    }
};

