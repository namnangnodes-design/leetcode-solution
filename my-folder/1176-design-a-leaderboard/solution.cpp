class Leaderboard {
public:
    map<int, set<int>, std::greater<int>> scores;
    int players[10001];
    Leaderboard() {
        scores.clear();
        for (int i = 1; i < 10001; i++)
        {
            players[i] = -1;
        }
    }
    
    void addScore(int playerId, int score) {
        if (players[playerId] == -1)
        {
            scores[score].insert(playerId);
            players[playerId] = score;
        }
        else
        {
            scores[players[playerId]].erase(playerId);
            players[playerId] += score;            
            scores[players[playerId]].insert(playerId);
        }
    }
    
    int top(int K) {
        int temp = K;
        int res = 0;
        for (auto score: scores)
        {
            if (temp <= score.second.size())
            {
                res += score.first * temp;
                return res;
            }
            else
            {
                res += score.first * score.second.size();
                temp -= score.second.size();
            }
        }
        return res;
    }
    
    void reset(int playerId) {
        scores[players[playerId]].erase(playerId);
        players[playerId] = 0;            
        scores[0].insert(playerId);
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */
