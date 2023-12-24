class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* start = new ListNode();
        ListNode* result = start;
        bool memHave = false;
        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val + l2->val + memHave < 10)
            {
                result->val = l1->val + l2->val + memHave;
                memHave = false;
            }
            else
            {
                result->val = l1->val + l2->val + memHave - 10;
                memHave = true;
            }
            if (l1->next != nullptr || l2->next != nullptr)
            {
                result->next = new ListNode();
                result = result->next;
            }
            l1 = l1->next;
            l2 = l2->next;
            
        }
        while (l1 != nullptr)
        {
            if (l1->val + memHave < 10)
            {
                result->val = l1->val + memHave;
                memHave = false;
            }
            else
            {
                result->val = l1->val + memHave - 10;
                memHave = true;
            }
            if (l1->next != nullptr)
            {
                result->next = new ListNode();
                result = result->next;
            }
            l1 = l1->next;
        }
        while (l2 != nullptr)
        {
            if (l2->val + memHave < 10)
            {
                result->val = l2->val + memHave;
                memHave = false;
            }
            else
            {
                result->val = l2->val + memHave - 10;
                memHave = true;
            }
            if (l2->next != nullptr)
            {
                result->next = new ListNode();
                result = result->next;
            }
            l2 = l2->next;
            
        }
        if (memHave)
        {
            result->next = new ListNode(1);
        }
     
        return start;
    }
};
