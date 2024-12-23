class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> startVec;
        vector<vector<int>> endVec;
        vector<bool> visited;
        int result = 0;
        for (int i = 0; i < n; i++)
        {
            vector<int> temp;
            startVec.push_back(temp);
            endVec.push_back(temp);
            visited.push_back(false);
        }
        for (int i = 0; i < connections.size(); i++)
        {
            int start = connections.at(i).at(0);
            int end = connections.at(i).at(1);
            startVec.at(end).push_back(start);
            endVec.at(start).push_back(end);
        }
        queue<int> road;
        visited.at(0) = true;
        for (int i = 0; i < startVec.at(0).size(); i++)
        {
            visited.at(startVec.at(0).at(i)) = true;
            road.push(startVec.at(0).at(i));
        }
        for (int i = 0; i < endVec.at(0).size(); i++)
        {
            result++;
            visited.at(endVec.at(0).at(i)) = true;
            road.push(endVec.at(0).at(i));
        }
        while (!road.empty())
        {
            int cur = road.front();
            road.pop();
            for (int i = 0; i < startVec.at(cur).size(); i++)
            {
                if (!visited.at(startVec.at(cur).at(i)))
                {
                    visited.at(startVec.at(cur).at(i)) = true;
                    road.push(startVec.at(cur).at(i));
                }
            }
            for (int i = 0; i < endVec.at(cur).size(); i++)
            {
                if (!visited.at(endVec.at(cur).at(i)))
                {
                    result++;
                    visited.at(endVec.at(cur).at(i)) = true;
                    road.push(endVec.at(cur).at(i));
                }
            }
        }
        return result;
    }
};
