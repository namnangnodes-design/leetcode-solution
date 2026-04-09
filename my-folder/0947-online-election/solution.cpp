class TopVotedCandidate {
public:
    unordered_map<int, int> pMap;
    vector<int> ranks;
    vector<int> mTimes;

    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int n = persons.size();
        mTimes = times;
        pMap.clear();
        ranks.clear();
        int bestCandidate = persons[0];
        int maxVote = 1;
        pMap[bestCandidate] = maxVote;
        ranks.push_back(bestCandidate);
        for (int i = 1; i < n; i++)
        {
            pMap[persons[i]]++;
            if (pMap[persons[i]] >= maxVote)
            {
                maxVote = pMap[persons[i]];
                bestCandidate = persons[i];
            }
            ranks.push_back(bestCandidate);
        }
    }
    
    int q(int t) {
        int i = upper_bound(mTimes.begin(), mTimes.end(), t) - mTimes.begin() - 1;
        return ranks[i];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
