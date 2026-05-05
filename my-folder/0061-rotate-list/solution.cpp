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
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* cur = head;
        if (head == nullptr || head->next == nullptr) return head;
        vector<ListNode*> v;
        while (cur != nullptr)
        {
            v.push_back(cur);
            cur = cur->next;
        }
        int n = v.size();
        k = k % n;
        if (k == 0)
        {
            return head;
        }
        ListNode* root = v[n - k];
        v[n - k - 1]->next = nullptr;
        v[n - 1]->next = head;
        return root;
    }
};
