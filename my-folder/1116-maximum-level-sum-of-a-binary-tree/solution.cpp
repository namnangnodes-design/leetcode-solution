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
    vector<int> sumVec;

    int maxLevelSum(TreeNode* root) {
        sumVec.clear();
        sumVec.push_back(0);
        traverse(root, 1);
        int result = 1;
        for (int i = 2; i < sumVec.size(); i++)
        {
            if (sumVec.at(result) < sumVec.at(i))
            {
                result = i;
            }
        }
        return result;
    }

    void traverse(TreeNode* root, int level)
    {
        if (root == nullptr)
        {
            return;
        }
        if (sumVec.size() == level)
        {
            sumVec.push_back(root->val);
        }
        else
        {
            sumVec.at(level) += root->val;
        }
        if (root->left != nullptr)
        {
            traverse(root->left, level + 1);
        }
        if (root->right != nullptr)
        {
            traverse(root->right, level + 1);
        }
    }
};
