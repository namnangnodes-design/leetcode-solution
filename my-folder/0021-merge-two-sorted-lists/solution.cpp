
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr && list2 == nullptr)
        {
            return nullptr;
        }
        else if (list2 == nullptr)
        {
            return list1;
        }
        else if (list1 == nullptr)
        {
            return list2;
        }
        ListNode* head = new ListNode();
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        ListNode* temp = head;
        if (temp1->val >= temp2->val)
        {
            temp->val = temp2->val;
            temp2 = temp2->next;
        }
        else
        {
            temp->val = temp1->val;
            temp1 = temp1->next;
        }
        while (temp1 != nullptr && temp2 != nullptr)
        {

            if (temp1->val >= temp2->val)
            {
                temp->next = new ListNode(temp2->val);
                temp2 = temp2->next;
                temp = temp->next;
            }
            else
            {
                temp->next = new ListNode(temp1->val);
                temp1 = temp1->next;
                temp = temp->next;
            }
        }
        while (temp1 != nullptr)
        {
            temp->next = new ListNode(temp1->val);
            temp = temp->next;
            temp1 = temp1->next;
        }
        while (temp2 != nullptr)
        {
            temp->next = new ListNode(temp2->val);
            temp = temp->next;
            temp2 = temp2->next;
        }
        return head;
    }
};
