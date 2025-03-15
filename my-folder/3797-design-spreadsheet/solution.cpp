class Spreadsheet {
public:
    int sheet[1001][26];
    Spreadsheet(int rows) {
        for (int i = 0; i <= 1000; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                sheet[i][j] = 0;
            }
        }
    }

    void setCell(string cell, int value) {
        int col = cell[0] - 'A';
        int row = cell[1] - '0';
        for (int i = 2; i < cell.length(); i++)
        {
            row = row * 10 + cell[i] - '0';
        }
        sheet[row][col] = value;
    }

    void resetCell(string cell) {
        setCell(cell, 0);
    }

    int getValue(string formula) {
        int plusIndex = formula.find('+', 1);
        int value1, value2 = 0;
        if ('0' <= formula[1] && formula[1] <= '9')
        {
            value1 = formula[1] - '0';
            for (int i = 2; i < plusIndex; i++)
            {
                value1 = value1 * 10 + formula[i] - '0';
            }
        }
        else
        {
            int col = formula[1] - 'A';
            int row = formula[2] - '0';
            for (int i = 3; i < plusIndex; i++)
            {
                row = row * 10 + formula[i] - '0';
            }
            value1 = sheet[row][col];
        }
        if ('0' <= formula[plusIndex + 1] && formula[plusIndex + 1] <= '9')
        {
            value2 = formula[plusIndex + 1] - '0';
            for (int i = plusIndex + 2; i < formula.length(); i++)
            {
                value2 = value2 * 10 + formula[i] - '0';
            }
        }
        else
        {
            int col = formula[plusIndex + 1] - 'A';
            int row = formula[plusIndex + 2] - '0';
            for (int i = plusIndex + 3; i < formula.length(); i++)
            {
                row = row * 10 + formula[i] - '0';
            }
            value2 = sheet[row][col];
        }
        //printf("plus %d 1 %d 2 %d \n", plusIndex, value1, value2);
        return value1 + value2;
    }
};
