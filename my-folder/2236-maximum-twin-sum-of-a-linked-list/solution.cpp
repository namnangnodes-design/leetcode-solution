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
    int pairSum(ListNode* head) {
     stack<ListNode*> listNodeStack;
     ListNode* cur = head;
     while (cur->next != nullptr)
     {
         listNodeStack.push(cur);
         cur = cur->next;
     }
     listNodeStack.push(cur);
     int maxSum = 0;
     cur = head;
     while (cur->next != nullptr)
     {
         maxSum = max(cur->val + listNodeStack.top()->val, maxSum);
         cur = cur->next;
         listNodeStack.pop();
     }
     return maxSum;
    }
};
