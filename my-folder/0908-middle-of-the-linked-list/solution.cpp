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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        int index = 0;
        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            index += 2;
            fast = fast->next->next;
            slow = slow->next;
        }
        if (fast->next == nullptr)
        {
            return slow;
        }
        return slow->next;
    }
};
