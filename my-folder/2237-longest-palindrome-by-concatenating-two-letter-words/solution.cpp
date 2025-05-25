class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<int, int> mMap;
        for (const string& word : words) {
            int index = (word[0] - 'a') * 100 + (word[1] - 'a');
            mMap[index]++;
        }

        int result = 0;
        bool haveMid = false;

        for (auto& pair : mMap) {
            int key = pair.first;
            int count = pair.second;
            int a = key / 100;
            int b = key % 100;

            if (a == b) {
                // Palindromic words like "aa", "bb", etc.
                result += (count / 2) * 4;
                if (count % 2 == 1) haveMid = true;
            } else {
                int reverseKey = b * 100 + a;
                if (key < reverseKey && mMap.count(reverseKey)) {
                    int pairCount = min(count, mMap[reverseKey]);
                    result += pairCount * 4;
                }
            }
        }

        if (haveMid) result += 2; // Place one palindromic word in the middle

        return result;
    }
};

