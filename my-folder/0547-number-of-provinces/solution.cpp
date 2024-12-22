class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> visited;
        int result = 0;
        for (int i = 0; i < isConnected.size(); i++)
        {
            visited.push_back(false);
        }
        for (int i = 0; i < isConnected.size(); i++)
        {
            if (visited.at(i))
            {
                continue;
            }
            result++;
            queue<int> provinces;
            provinces.push(i);
            visited[i] = true;
            while (!provinces.empty())
            {
                int cur = provinces.front();
                provinces.pop();
                for (int j = 0; j < isConnected.at(cur).size(); j++)
                {
                    if (!isConnected.at(cur).at(j) || visited.at(j))
                    {
                        continue;
                    }
                    provinces.push(j);
                    visited[j] = true;
                }
            }
        }
        return result;
    }
};
