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
    ListNode* deleteMiddle(ListNode* head) {
        int size = 1;
        ListNode* cur = head;
        while (cur->next)
        {
            size++;
            cur = cur->next;
        }
        if (size == 1)
        {
            return nullptr;
        }
        int mid = size / 2;
        int index = 0;
        cur = head;
        while (index != mid - 1)
        {
            cur = cur->next;
            index++;
        }
        cur->next = cur->next->next; 
        return head;
    }
};
