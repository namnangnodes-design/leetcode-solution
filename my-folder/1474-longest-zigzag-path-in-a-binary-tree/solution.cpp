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
    int maxLength=0;

    void traverse(TreeNode* root,int dir,int curLength){
        if(!root) return;
        maxLength=max(maxLength,curLength);
        traverse(root->left,0,dir?curLength+1:1);
        traverse(root->right,1,dir?1:curLength+1);
    }

    int longestZigZag(TreeNode* root) {
        traverse(root,0,0);
        traverse(root,1,0);
        return maxLength;
    }
};
