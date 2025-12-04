class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> times(n, 0);
        stack<int> run;
        int prev = 0;
        bool justStart = false;
        for (int i = 0; i < logs.size(); i++)
        {
            string s = logs[i];
            int _index = s.find(':');
            char c = s[_index + 1]; 
            if (c == 's')
            {
                int func = stoi(s.substr(0, _index));
                int time = stoi(s.substr(_index + 7, s.size() - _index - 7));
                if (!run.empty()) times[run.top()] += justStart ? (time - prev) : (time - 1 - prev);
                prev = time;
                justStart = true;
                run.push(func);
            }
            else if (c == 'e')
            {
                int func = stoi(s.substr(0, _index));
                int time = stoi(s.substr(_index + 5, s.size() - _index - 5));
                times[run.top()] += justStart ? (time - prev + 1) : (time - prev);
                prev = time;
                justStart = false;
                run.pop();
            }
        }
        return times;
    }
};
