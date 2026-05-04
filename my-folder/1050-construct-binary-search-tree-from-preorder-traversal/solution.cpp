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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        int n = preorder.size();
        stack<TreeNode*> mS;
        mS.push(root);
        for (int i = 1; i < n; i++)
        {
            int curVal = preorder[i];
            TreeNode* cur = new TreeNode(curVal);
            if (curVal < mS.top()->val)
            {
                mS.top()->left = cur;
            }
            else
            {
                TreeNode* parent = mS.top();
                while (!mS.empty() && mS.top()->val < curVal)
                {
                    parent = mS.top();
                    mS.pop();
                }
                parent->right = cur;
            }
            mS.push(cur);
        }
        return root;
    }
};
