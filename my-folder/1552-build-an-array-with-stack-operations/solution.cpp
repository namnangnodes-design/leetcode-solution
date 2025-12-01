class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        string push = "Push";
        string pop = "Pop";
        vector<string> res;
        int stream = 1;
        for (int i = 0; i < target.size(); i++)
        {
            if (stream == target[i])
            {
                res.push_back(push);
                stream++;
            }
            else if (stream < target[i])
            {
                for (int j = 0; j < target[i] - stream; j++)
                {
                    res.push_back(push);
                    res.push_back(pop);
                }
                res.push_back(push);
                stream = target[i] + 1;
            }
        }
        return res;
    }
};
