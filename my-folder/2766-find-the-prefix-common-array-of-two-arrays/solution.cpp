class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<bool> countA(n + 1, false);
        vector<bool> countB(n + 1, false);
        vector<int> res(n, 0);
        countA[A[0]] = true;
        countB[B[0]] = true; 
        res[0] = A[0] == B[0];
        for (int i = 1; i < n; i++)
        {
            countA[A[i]] = true;
            countB[B[i]] = true;
            if (A[i] == B[i])
            {
                res[i] = res[i - 1] + 1;
            }
            else
            {
                int temp = res[i - 1];
                if (countA[A[i]] == countB[A[i]])
                {
                    temp++;
                }
                if (countA[B[i]] == countB[B[i]])
                {
                    temp++;
                }
                res[i] = temp;
            }
        }
        return res;
    }
};
