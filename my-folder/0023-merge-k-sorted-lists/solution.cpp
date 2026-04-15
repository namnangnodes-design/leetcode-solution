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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> v;
        int n = lists.size();
        for (int i = 0; i < lists.size(); i++)
        {
            ListNode* cur = lists[i];
            while (cur != nullptr)
            {
                v.push_back(cur->val);
                cur = cur->next;
            }
        }
        if (v.size() == 0) return nullptr;
        sort(v.begin(), v.end());
        ListNode* head = new ListNode(v[0]);
        ListNode* cur = head;
        for (int i = 1; i < v.size(); i++)
        {
            cur->next = new ListNode(v[i]);
            cur = cur->next;
        }
        return head;
    }
};
