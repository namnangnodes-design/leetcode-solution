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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode* cur = head;
        ListNode* lastNode = cur;
        int size = 1;
        while (cur->next != nullptr)
        {
            size++;
            cur = cur->next;
            lastNode = cur;
        }
        int index = 0;
        cur = head;
        while (index < size/2)
        {
            lastNode->next = cur->next;
            cur->next = cur->next->next;
            index++;
            lastNode = lastNode->next;
            cur = cur->next;
        }
        lastNode->next = nullptr;
        return head;
    }
};
