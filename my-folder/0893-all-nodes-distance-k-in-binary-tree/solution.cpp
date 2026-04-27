class Solution {
public:
    vector<int> res;

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        res.clear();
        if (!root || !target) return res;

        vector<TreeNode*> path;
        findPath(root, target, path);

        for (int i = 0; i < path.size(); i++) {
            TreeNode* blocked = (i == 0 ? nullptr : path[i - 1]);
            collect(path[i], k - i, blocked);
        }

        return res;
    }

    bool findPath(TreeNode* cur, TreeNode* target, vector<TreeNode*>& path) {
        if (!cur) return false;

        if (cur == target) {
            path.push_back(cur);
            return true;
        }

        if (findPath(cur->left, target, path) ||
            findPath(cur->right, target, path)) {
            path.push_back(cur);
            return true;
        }

        return false;
    }

    void collect(TreeNode* cur, int dist, TreeNode* blocked) {
        if (!cur || dist < 0) return;

        if (cur == blocked) return;

        if (dist == 0) {
            res.push_back(cur->val);
            return;
        }

        collect(cur->left, dist - 1, blocked);
        collect(cur->right, dist - 1, blocked);
    }
};
