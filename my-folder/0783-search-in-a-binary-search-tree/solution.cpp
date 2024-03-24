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
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* result = root;
        while (result != nullptr)
        {
        if (val < result->val)
        {
            result = result->left;
        } 
        else if (val > result->val)
        {
            result = result->right;
        } 
        else
        {
            return result;
        }
        }
        return nullptr;
    }
};
