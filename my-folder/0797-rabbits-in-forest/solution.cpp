class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> mMap;
        int result = 0;
        for (int i = 0; i < answers.size(); i++)
        {
            if (answers[i] == 0)
            {
                result++;
                continue;
            }
            mMap[answers[i]]++;
            if (mMap[answers[i]] == answers[i] + 2)
            {
                //printf("answers[i] %d \n", answers[i]);
                result += answers[i] + 1;
                mMap[answers[i]] = 1;
            }
        }
        for (pair<int, int> i: mMap)
        {
            //printf("i.first %d \n", i.first);
            result += i.first + 1;
        }
        return result;
    }
};
