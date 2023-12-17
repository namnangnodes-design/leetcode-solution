class Solution {
public:
    vector<string> result;
    string temp = "";
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0)
        {
            return result;
        }
        backtrack(0, digits);
        return result;
    }

    void backtrack(int i, string str) {
        if (i == str.length())
        {
            result.push_back(temp);
            return;
        }
        switch (str.at(i))
        {
        case '2':
        {
            temp.push_back('a');
            backtrack(i + 1, str);
            temp.pop_back();
            temp.push_back('b');
            backtrack(i + 1, str);
            temp.pop_back();
            temp.push_back('c');
            backtrack(i + 1, str);
            temp.pop_back();
            break;
        }
        case '3':
        {
            temp.push_back('d');
            backtrack(i + 1, str);
            temp.pop_back();
            temp.push_back('e');
            backtrack(i + 1, str);
            temp.pop_back();
            temp.push_back('f');
            backtrack(i + 1, str);
            temp.pop_back();
            break;
        }
        case '4':
        {
            temp.push_back('g');
            backtrack(i + 1, str);
            temp.pop_back();
            temp.push_back('h');
            backtrack(i + 1, str);
            temp.pop_back();
            temp.push_back('i');
            backtrack(i + 1, str);
            temp.pop_back();
            break;
        }
        case '5':
        {
            temp.push_back('j');
            backtrack(i + 1, str);
            temp.pop_back();
            temp.push_back('k');
            backtrack(i + 1, str);
            temp.pop_back();
            temp.push_back('l');
            backtrack(i + 1, str);
            temp.pop_back();
            break;
        }
        case '6':
        {
            temp.push_back('m');
            backtrack(i + 1, str);
            temp.pop_back();
            temp.push_back('n');
            backtrack(i + 1, str);
            temp.pop_back();
            temp.push_back('o');
            backtrack(i + 1, str);
            temp.pop_back();
            break;
        }
        case '7':
        {
            temp.push_back('p');
            backtrack(i + 1, str);
            temp.pop_back();
            temp.push_back('q');
            backtrack(i + 1, str);
            temp.pop_back();
            temp.push_back('r');
            backtrack(i + 1, str);
            temp.pop_back();
            temp.push_back('s');
            backtrack(i + 1, str);
            temp.pop_back();
            break;
        }
        case '8':
        {
            temp.push_back('t');
            backtrack(i + 1, str);
            temp.pop_back();
            temp.push_back('u');
            backtrack(i + 1, str);
            temp.pop_back();
            temp.push_back('v');
            backtrack(i + 1, str);
            temp.pop_back();
            break;
        }
        case '9':
        {
            temp.push_back('w');
            backtrack(i + 1, str);
            temp.pop_back();
            temp.push_back('x');
            backtrack(i + 1, str);
            temp.pop_back();
            temp.push_back('y');
            backtrack(i + 1, str);
            temp.pop_back();
            temp.push_back('z');
            backtrack(i + 1, str);
            temp.pop_back();
            break;
        }
        }
    }
};
