class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        if (n != goal.size()) return false;
        s.append(s);
        return s.find(goal) != string::npos;
    }
};
