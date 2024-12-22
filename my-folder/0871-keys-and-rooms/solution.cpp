class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> visitQueue;
        unordered_set<int> visitSet;
        visitSet.insert(0);
        for (int i = 0; i < rooms.at(0).size(); i++)
        {
            int toAdd = rooms.at(0).at(i);
            if (visitSet.find(toAdd) == visitSet.end())
            {
                visitSet.insert(toAdd);
                visitQueue.push(toAdd);
            }
        }
        while (!visitQueue.empty())
        {
            int curRoom = visitQueue.front();
            visitQueue.pop();
            for (int i = 0; i < rooms.at(curRoom).size(); i++)
            {
                int toAdd = rooms.at(curRoom).at(i);
                if (visitSet.find(toAdd) == visitSet.end())
                {
                    visitSet.insert(toAdd);
                    visitQueue.push(toAdd);
                }
            }
        }
        if (visitSet.size() >= rooms.size())
        {
            return true;
        }
        return false;
    }
};
