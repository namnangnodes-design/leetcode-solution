/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<string> binaryList;

    int sumRootToLeaf(TreeNode* root) {
        binaryList.clear();
        sumRoot(root, "");
        int sum = 0;
        for (int i = 0; i < binaryList.size(); i++)
        {
            string s = binaryList[i];
            for (int j = s.size() - 1, k = 0; j > -1; j--, k++)
            {
                sum += (s[j] - 48) * (int)pow(2, k);
            }
        }
        return sum;
    }
    
    void sumRoot(TreeNode* node, string s)
    {
        if (node == nullptr) return;
        s.push_back(node->val + 48);
        if (node->left == nullptr && node->right == nullptr)
        {
            binaryList.push_back(s);
            return;
        }
        if (node->left != nullptr)
        {
            sumRoot(node->left, s);
        }
        if (node->right != nullptr)
        {
            sumRoot(node->right, s);
        }
    }
};
