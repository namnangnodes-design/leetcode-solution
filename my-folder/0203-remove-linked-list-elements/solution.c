/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    while (head != NULL && head->val == val)
    {
        head = head->next;
    }
    struct ListNode* cur = head;
    if (cur == NULL || cur->val == val) return NULL;
    if (cur->next == NULL )
    {
        return head;
    }   
    while (cur != NULL && cur->next != NULL)
    {
        while (cur->next != NULL && cur->next->val == val)
        {
            cur->next = cur->next->next;
        }
        cur = cur->next;
    }
    return head;
}
