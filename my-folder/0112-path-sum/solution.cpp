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
    int mTarget;

    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;
        if (root->val == targetSum && root->left == nullptr && root->right == nullptr) return true;
        if (root->left == nullptr) root->left = new TreeNode(10000);
        if (root->right == nullptr) root->right = new TreeNode(10000);
        mTarget = targetSum;
        return inorder(root, root->val);
    }

    bool inorder(TreeNode* cur, int curSum)
    {
        if (cur->left == nullptr && cur->right == nullptr)
        {
            return curSum == mTarget;
        }
        else if (cur->left == nullptr)
        {
            return inorder(cur->right, curSum + cur->right->val);
        }
        else if (cur->right == nullptr)
        {
            return inorder(cur->left, curSum + cur->left->val);
        }
        else
        {
            return inorder(cur->right, curSum + cur->right->val) | inorder(cur->left, curSum + cur->left->val);;
        }
    }
};
