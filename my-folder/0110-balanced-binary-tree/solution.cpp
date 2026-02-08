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
    bool res;
    bool isBalanced(TreeNode* root) {
        res = true;
        recur(root);
        return res;
    }
    int recur(TreeNode* root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int a = recur(root->left);
        int b = recur(root->right);
        if (abs(a - b) > 1) 
        {
            res = false;
            return -1;
        }
        return max(a, b) + 1;
    }
};
