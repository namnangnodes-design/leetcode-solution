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
    vector<pair<int, int>> mPairs;
    vector<int> mResult;
    int mRank;
    void traverse(TreeNode *node, int rank)
    {
        if (node == nullptr)
        {
            return;
        }
        mRank = max(mRank, rank);
        mPairs.push_back({rank, node->val });
        if (node->right != nullptr)
        {
            traverse(node->right, rank + 1);
        }
        if (node->left != nullptr)
        {
            traverse(node->left, rank + 1);
        }
    }

    vector<int> rightSideView(TreeNode* root) {
        mResult.clear();
        if (root == nullptr) return mResult;
        traverse(root, 0);
        // for (int i = 0; i < mPairs.size(); i++)
        // {
        //     cout << mPairs[i].first << " " << mPairs[i].second << std::endl;
        // }
        // cout << mRank;
        int index = 0;
        for (int i = 0; i <= mRank; i++)
        {
            while (index < mPairs.size())
            {
                if (mPairs[index].first == i)
                {
                    mResult.push_back(mPairs[index].second);
                    break;
                }
                index++;
            }
        }
        return mResult;
    }
};
