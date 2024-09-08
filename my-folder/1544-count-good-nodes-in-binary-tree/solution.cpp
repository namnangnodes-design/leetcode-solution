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
int result = 0;

void traversalTree(TreeNode* root, int maxPath)
{
    if (root->val > maxPath)
    {
        maxPath = root->val;
    }
    if (root->val >= maxPath)
    {
        result++;
    }
    if (root->left != nullptr)
    {
        traversalTree(root->left, maxPath);
    }
    if (root->right != nullptr)
    {
        traversalTree(root->right, maxPath);
    }
}

int goodNodes(TreeNode* root) {
    result = 0;
    traversalTree(root, -pow(10, 4) - 1);
    return result;
}
};
