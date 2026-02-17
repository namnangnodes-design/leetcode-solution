class Solution {
public:
    unordered_map<int, vector<string>> hours = {
        {0, {"0"}},
        {1, {"1", "2", "4", "8"}},
        {2, {"3", "5", "6", "9", "10"}},
        {3, {"7", "11"}}
    };
    unordered_map<int, vector<string>> minutes = {
        {0, {"00"}},
        {1, {"01", "02", "04", "08", "16", "32"}},
        {2, {"03", "05", "06", "09", "10", "12", "17", "18", "20", "24", "33", "34", "36", "40", "48"}},
        {3, {"07", "11" , "13", "14", "19", "21", "22", "25", "26", "28", "35", "37", "38", "41", "42", "44", "49", "50", "52", "56"}},
        {4, {"15", "23", "27", "29", "30", "39", "43", "45", "46", "51", "53", "54", "57", "58"}},
        {5, {"31", "47", "55", "59"}} 
    };
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> res;
        if (turnedOn <= 5) 
        {
            for (int j = 0; j < minutes[turnedOn].size(); j++)
            {
                string temp = "0";
                temp.push_back(':');
                temp.append(minutes[turnedOn][j]);
                res.push_back(temp);
            }
        }
        for (int i = 0; i < hours[1].size(); i++)
        {
            if (turnedOn - 1 > 5) break;
            for (int j = 0; j < minutes[turnedOn - 1].size(); j++)
            {
                string temp = hours[1][i];
                temp.push_back(':');
                temp.append(minutes[turnedOn - 1][j]);
                res.push_back(temp);
            }
        }
        for (int i = 0; i < hours[2].size(); i++)
        {
            if (turnedOn - 2 > 5) break;
            for (int j = 0; j < minutes[turnedOn - 2].size(); j++)
            {
                string temp = hours[2][i];
                temp.push_back(':');
                temp.append(minutes[turnedOn - 2][j]);
                res.push_back(temp);
            }
        }
        for (int i = 0; i < hours[3].size(); i++)
        {
            if (turnedOn - 3 > 5) break;
            for (int j = 0; j < minutes[turnedOn - 3].size(); j++)
            {
                string temp = hours[3][i];
                temp.push_back(':');
                temp.append(minutes[turnedOn - 3][j]);
                res.push_back(temp);
            }
        }
        return res;
    }
};
