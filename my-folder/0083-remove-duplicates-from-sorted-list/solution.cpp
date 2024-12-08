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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr)
        {
            return head;
        }
        ListNode* temp = head;
        while (temp != nullptr)
        {
            if (temp->next == nullptr)
            {
                return head;
            }
            ListNode* cur = temp->next;
            while (cur!= nullptr && cur->val == temp->val)
            {
                cur = cur->next;
            }
            temp->next = cur;
            temp = temp->next;
        }
        return head;
    }
};
