class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        int score = 0;
        int counter =0;
        int n = events.size();
        for (int i = 0; i < n; i++)
        {
            if (counter == 10) return {score, counter};
            if (events[i] == "W")
            {
                counter++;
            }
            else if (events[i] == "WD")
            {
                score++;
            }
            else if (events[i] == "NB")
            {
                score++;
            }
            else
            {
                score += stoi(events[i]);
            }
        }
        return {score, counter};
    }
};
