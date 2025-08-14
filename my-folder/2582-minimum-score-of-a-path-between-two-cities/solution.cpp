class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<bool> canVisit1;
        vector<bool> canVisitN;
        for (int i = 0; i <= n; i++)
        {
            canVisit1.push_back(false);
            canVisitN.push_back(false);
        }
        canVisit1[1] = true;
        canVisitN[n] = true;
        unordered_map<int, unordered_set<int>> mMap; 
        for (int i = 0; i < roads.size(); i++)
        {
            if (mMap.find(roads[i][0]) == mMap.end())
            {
                unordered_set<int> t;
                t.insert(roads[i][1]);
                mMap.insert({roads[i][0], t});
            }
            else
            {
                mMap[roads[i][0]].insert(roads[i][1]);
            }
            if (mMap.find(roads[i][1]) == mMap.end())
            {
                unordered_set<int> t;
                t.insert(roads[i][0]);
                mMap.insert({roads[i][1], t});
            }
            else
            {
                mMap[roads[i][1]].insert(roads[i][0]);
            }
        }
        // for (auto i: mMap)
        // {
        //     cout << "index " << i.first << " ";
        //     for (int j: i.second)
        //     {
        //         cout << j << " ";
        //     }
        //     cout << endl;
        // }
        queue<int> mQ;
        mQ.push(1);
        while (!mQ.empty())
        {
            int s = mQ.front();
            mQ.pop();
            for (int i: mMap[s])
            {
                if (!canVisit1[i])
                {
                    mQ.push(i);
                    canVisit1[i] = true;            
                }
            }
        }
        mQ.push(n);
        while (!mQ.empty())
        {
            int s = mQ.front();
            mQ.pop();
            for (int i: mMap[s])
            {
                if (!canVisitN[i])
                {
                    mQ.push(i);
                    canVisitN[i] = true;            
                }
            }
        }
        int result = 10001;
        for (int i = 0; i < roads.size(); i++)
        {
            if (canVisit1[roads[i][0]] && canVisitN[roads[i][1]] && roads[i][2] < result)
            {
                result = roads[i][2];
            }
        }
        // for (int i = 0; i <= n; i++)
        // {
        //     cout << i << " " << canVisit1[i] << " ";
        // }
        // cout << endl;
        // for (int i = 0; i <= n; i++)
        // {
        //     cout << i << " " << canVisitN[i] << " ";
        // }
        // cout << endl;
        return result;
    }
};
