class Solution {
public:
    // Check if two words differ by at most 2 characters
    bool withinTwoEdits(const string& a, const string& b) {
        int diff = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) {
                diff++;
                if (diff > 2) return false;
            }
        }
        return true;
    }
    
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> res;
        
        for (const string& query : queries) {
            for (const string& dictWord : dictionary) {
                if (withinTwoEdits(query, dictWord)) {
                    res.push_back(query);
                    break; // Found a match, move to next query
                }
            }
        }
        
        return res;
    }
};
