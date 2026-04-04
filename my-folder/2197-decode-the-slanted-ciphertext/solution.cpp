class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        if (!encodedText.size()) return "";
        string res;
        vector<vector<char>> simulate;
        int col = encodedText.size() / rows;
        for (int i = 0; i < rows; i++)
        {
            vector<char> temp;
            for (int j = 0; j < col; j++)
            {
                temp.push_back(encodedText[i * col + j]);
            }
            simulate.push_back(temp);
        }
        for (int i = 0; i <= col - rows + 1; i++)
        {
            for (int j = 0; j < rows; j++)
            {
                if (j + i >= col) break;
                res.push_back(simulate[j][j + i]);
            }
        }
        while (res[res.size() - 1] == ' ') res.pop_back();
        return res;
    }
};
