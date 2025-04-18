class Solution {
public:
    string result[31] = {};

    string countAndSay(int n) {
        if (result[1].empty()) {
            result[1] = "1";
            for (int i = 2; i <= 30; ++i) {
                string& prev = result[i - 1];
                string& curr = result[i];
                int count = 1;
                for (int j = 1; j < prev.size(); ++j) {
                    if (prev[j] == prev[j - 1]) {
                        ++count;
                    } else {
                        curr += to_string(count) + prev[j - 1];
                        count = 1;
                    }
                }
                // Append the last group
                curr += to_string(count) + prev.back();
            }
        }
        return result[n];
    }
};

