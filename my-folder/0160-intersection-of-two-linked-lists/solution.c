/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if (headA == NULL || headB == NULL) return NULL;
    int aCount = 0;
    int bCount = 0;
    struct ListNode* curA = headA;
    struct ListNode* curB = headB;
    while (curA != NULL)
    {
        curA = curA->next;
        aCount++;
    }
    while (curB != NULL)
    {
        curB = curB->next;
        bCount++;
    }
    if (curA != curB && curA != NULL) return NULL;
    if (aCount >= bCount)
    {
        int minus = aCount - bCount;
        curA = headA;
        curB = headB;
        while (minus > 0)
        {
            curA = curA->next;
            minus--;
        }
        while (curA != curB)
        {
            curA = curA->next;
            curB = curB->next;
        }
    }
    else
    {
        int minus = bCount - aCount;
        curA = headA;
        curB = headB;
        while (minus > 0)
        {
            curB = curB->next;
            minus--;
        }
        while (curA != curB)
        {
            curA = curA->next;
            curB = curB->next;
        }
    }
    return curA;
}
