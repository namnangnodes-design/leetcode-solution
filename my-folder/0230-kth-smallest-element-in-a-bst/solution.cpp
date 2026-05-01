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
    vector<int> mV;
    int kthSmallest(TreeNode* root, int k) {
        mV.clear();
        preOrder(root);
        return mV[k - 1];
    }

    void preOrder(TreeNode* cur)
    {
        if (cur == nullptr)
        {
            return;
        }
        if (cur->left != nullptr) 
        {
            preOrder(cur->left);
        }
        mV.push_back(cur->val);
        if (cur->right != nullptr) 
        {
            preOrder(cur->right);
        }
    }


};
