class Solution {
public:
    string predictPartyVictory(string s) {
        queue<int>radiantQ ; 
        queue<int>direQ ; 
        int n = s.length() ; 
        for(int i = 0 ; i < n ; i++){
            (s[i] == 'R') ? radiantQ.push(i) : direQ.push(i) ;
        }
        while(!radiantQ.empty() && !direQ.empty()){
            int x , y ; 
            x = radiantQ.front(); 
            y = direQ.front(); 
            radiantQ.pop() ; 
            direQ.pop() ; 
            (x < y) ? radiantQ.push(n + x) : direQ.push(n + y) ; 
        }
        return !radiantQ.empty() ? "Radiant" : "Dire" ; 
    }
};
