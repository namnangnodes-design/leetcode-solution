/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    vector<int> mV;
    TreeNode* mRes;
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr) return nullptr;
        mV.clear();
        ListNode* cur = head;
        while (cur != nullptr)
        {
            mV.push_back(cur->val);
            cur = cur->next;
        }
        mRes = buildBinary(0, mV.size() - 1);
        return mRes;
    }

    TreeNode* buildBinary(int l, int r)
    {
        int m = l + (r - l) / 2;
        if (l >= r)
        {
            TreeNode* node = new TreeNode(mV[m]);
            return node;
        }
        TreeNode* node = new TreeNode(mV[m]);
        if (r - l == 1)
        {
            if (m == r)
            {
                node->left = new TreeNode(mV[l]);
            } 
            else if (l == m)
            {
                node->right = new TreeNode(mV[r]);
            }
        }
        else
        {
            node->left = buildBinary(l, m - 1);
            node->right = buildBinary(m + 1, r);
        }
        return node;
    }
};
