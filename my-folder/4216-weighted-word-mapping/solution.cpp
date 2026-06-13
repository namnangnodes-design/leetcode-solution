class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string res;
        for (string w: words)
        {
            int sum = 0;
            for (int i = 0; i < w.size(); i++)
            {
                sum += weights[w[i] - 'a']; 
            }
            res.push_back(25 - sum % 26 + 'a');
        }
        return res;
    }
};
