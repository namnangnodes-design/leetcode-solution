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
    unordered_map<long long, int> hmap;
    int count;

    int pathSum(TreeNode* root, int targetSum) {
        hmap.clear();
        count = 0;
        dfs(root, 0, targetSum);
        return count;
    }
    void dfs(TreeNode* root, long long prefixSum, int targetSum) {
        if (root == nullptr) return;

        prefixSum += root->val;

        if (hmap.find(prefixSum - targetSum) != hmap.end()) {
            count += hmap[prefixSum - targetSum];
        }

        if (prefixSum == targetSum) {
            count++;
        }

        hmap[prefixSum]++;

        dfs(root->left, prefixSum, targetSum);
        dfs(root->right, prefixSum, targetSum);

        hmap[prefixSum]--;
    }
};
