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
    vector<int> inorder;
    
    TreeNode* balanceBST(TreeNode* root) {
        inorder.clear();
        traversal(root);
        return create(0, inorder.size() - 1);    
    }
    void traversal(TreeNode* root)
    {
        if (root == nullptr)
        {
            return;
        }
        traversal(root->left);
        inorder.push_back(root->val);
        traversal(root->right);
    }
    TreeNode* create(int start, int end)
    {
        if (start > end) return nullptr;
        int mid = start + (end - start) / 2;
        TreeNode* leftNode = create(start, mid - 1);
        TreeNode* rightNode = create(mid + 1, end);
        return new TreeNode(inorder[mid], leftNode, rightNode);
    }
};
