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
int maxDepth(TreeNode* root) {
    if (root == nullptr)
    {
        return 0;
    }
    queue<TreeNode*> mQueue;
    queue<int> mRank;
    mQueue.push(root);
    mRank.push(1);
    int result = 1;
    while (!mQueue.empty())
    {
        TreeNode* curNode = mQueue.front();
        int curRank = mRank.front();
        result = max(result, curRank);
        if (curNode->left != nullptr)
        {
            mQueue.push(curNode->left);
            mRank.push(curRank + 1);
        }
        if (curNode->right != nullptr)
        {
            mQueue.push(curNode->right);
            mRank.push(curRank + 1);
        }
        mQueue.pop();
        mRank.pop();
    }
    return result;
}
};
