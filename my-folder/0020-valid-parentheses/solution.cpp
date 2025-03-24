class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++)
        {
            char temp = s[i]; 
            if(temp=='(' || temp=='{' || temp=='[')st.push(temp);
            else
            {
                if(st.empty())return false;
                if((temp==')' && st.top()!='(') || (temp=='}' && 
                st.top()!='{') || (temp==']' && st.top()!='['))return false;
                st.pop();
            }
        }
        return st.empty();
    }
};
