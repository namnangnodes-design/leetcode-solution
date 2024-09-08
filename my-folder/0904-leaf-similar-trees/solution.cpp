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
vector<int> treeVec;

void visited(TreeNode* root)
{
    if (root->left == nullptr && root->right == nullptr)
    {
        treeVec.push_back(root->val);
    }
}

void traversalTree(TreeNode* root)
{
    if (root->left != nullptr)
    {
        traversalTree(root->left);
    }
    visited(root);
    if (root->right != nullptr)
    {
        traversalTree(root->right);
    }
}

bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    if (root1 == nullptr && root2 == nullptr)
    {
        return true;
    }
    else if (root1 == nullptr || root2 == nullptr)
    {
        return false;
    }
    treeVec.clear();
    traversalTree(root1);
    vector<int> vec1 = treeVec;
    treeVec.clear();
    traversalTree(root2);
    vector<int> vec2 = treeVec;
    if (vec1.size() != vec2.size())
    {
        return false;
    }
    for (int i = 0; i < vec1.size(); i++)
    {
        if (vec1[i] != vec2[i])
        {
            return false;
        }
    }
    return true;
}
};
