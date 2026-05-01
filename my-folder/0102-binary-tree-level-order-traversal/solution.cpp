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
    vector<vector<int>> res;
    vector<vector<int>> levelOrder(TreeNode* root) {
        inOrder(root, 0);
        return res;
    }

    void inOrder(TreeNode* cur, int rank)
    {
        if (cur == nullptr) return;
        if (res.size() == rank)
        {
            res.push_back({});
        }
        res[rank].push_back(cur->val);
        inOrder(cur->left, rank + 1);
        inOrder(cur->right, rank + 1);
    }
};
