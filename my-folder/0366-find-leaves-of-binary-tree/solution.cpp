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
    vector<vector<int>> mRes;
    vector<vector<int>> findLeaves(TreeNode* root) {
        mRes.clear();
        inOrder(root);
        return mRes;
    }

    int inOrder(TreeNode* cur)
    {
        if (cur->left == nullptr && cur->right == nullptr)
        {
            if (mRes.size() <= 0) 
            {
                mRes.push_back({});
            }
            mRes[0].push_back(cur->val);
            return 0;          
        }
        else if (cur->left == nullptr)
        {
            int rank = inOrder(cur->right) + 1;
            if (mRes.size() <= rank) 
            {
                mRes.push_back({});
            }
            mRes[rank].push_back(cur->val);
            return rank;  
        }
        else if (cur->right == nullptr)
        {
            int rank = inOrder(cur->left) + 1;
            if (mRes.size() <= rank) 
            {
                mRes.push_back({});
            }
            mRes[rank].push_back(cur->val);
            return rank;  
        }
        else 
        {
            int rank = max(inOrder(cur->left) + 1, inOrder(cur->right) + 1);
            if (mRes.size() <= rank) 
            {
                mRes.push_back({});
            }
            mRes[rank].push_back(cur->val);
            return rank; 
        }
    }
};
