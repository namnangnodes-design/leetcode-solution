/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode dummy; 
    struct ListNode* cur = &dummy;
    struct ListNode* cur1 = list1;
    struct ListNode* cur2 = list2;
    while (cur1 != NULL && cur2 != NULL)
    {
        if (cur1->val <= cur2->val)
        {
            cur->next = cur1;
            cur1 = cur1->next;
        }
        else
        {
            cur->next = cur2;
            cur2 = cur2->next;
        }
        cur = cur->next;
    }
    while (cur1 != NULL)
    {
        cur->next = cur1;
        cur1 = cur1->next;
        cur = cur->next;
    }
    while (cur2 != NULL)
    {
        cur->next = cur2;
        cur2 = cur2->next;
        cur = cur->next;
    }
    return dummy.next; 
}
