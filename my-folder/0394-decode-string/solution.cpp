class Solution {
public:
string decodeString(string s) {
    stack<int> st;
    stack<string> st1;
    string sb;
    int n = 0;

    for (char c : s) {
        if (c <= '9' && c >= '0') {
            n = n * 10 + (c - '0');
        }
        else if (c == '[') {
            st.push(n);
            n = 0;
            st1.push(sb);
            sb = "";
        }
        else if (c == ']') {
            int k = st.top();
            st.pop();
            string temp = sb;
            sb = st1.top();
            st1.pop();
            while (k-- > 0) {
                sb.append(temp);
            }
        }
        else {
            sb.push_back(c);
        }
    }

    return sb;
}
};
