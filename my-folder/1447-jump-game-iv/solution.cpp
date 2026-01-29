class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>> mMap;
        for (int i = 0; i < arr.size(); i++)
        {
            if (mMap.find(arr[i]) != mMap.end())
            {
                mMap[arr[i]].push_back(i);
            }
            else
            {
                vector<int> temp;
                temp.push_back(i);
                mMap[arr[i]] = temp;
            }
        }
        queue<pair<int, int>> road;
        vector<bool> visited(arr.size(), false);
        road.push({0, 0});
        visited[0] = true;
        while (!road.empty())
        {
            pair<int, int> cur = road.front();
            if (cur.first == arr.size() - 1) return cur.second;
            road.pop();
            if (cur.first - 1 >= 0 && !visited[cur.first - 1])
            {
                road.push({cur.first - 1, cur.second + 1});
                visited[cur.first - 1] = true;
            }
            if (cur.first + 1 < arr.size() && !visited[cur.first + 1])
            {
                road.push({cur.first + 1, cur.second + 1});
                visited[cur.first + 1] = true;
            }
            
            for (int j: mMap[arr[cur.first]])
            {   
                if (!visited[j])
                {
                    road.push({j, cur.second + 1});
                    visited[j] = true;
                }
            }
            mMap.erase(arr[cur.first]);
        }
        return -1;
    }
};
