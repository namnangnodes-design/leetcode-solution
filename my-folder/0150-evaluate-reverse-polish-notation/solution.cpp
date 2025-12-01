class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> numStack;
        for (string s: tokens)
        {
            if (s == "+")
            {
                int a = numStack.top();
                numStack.pop();
                int b = numStack.top();
                numStack.pop();
                numStack.push(a + b);
            }
            else if (s == "-")
            {
                int a = numStack.top();
                numStack.pop();
                int b = numStack.top();
                numStack.pop();
                numStack.push(b - a);
            }
            else if (s == "*")
            {
                int a = numStack.top();
                numStack.pop();
                int b = numStack.top();
                numStack.pop();
                numStack.push(a * b);
            }
            else if (s == "/")
            {
                int a = numStack.top();
                numStack.pop();
                int b = numStack.top();
                numStack.pop();
                numStack.push(b / a);
            }
            else
            {
                numStack.push(stoi(s));
            }
        }
        return numStack.top();
    }
};
