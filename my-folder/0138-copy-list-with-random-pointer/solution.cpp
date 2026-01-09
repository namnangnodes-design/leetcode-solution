/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        Node* newHead = new Node(head->val);
        Node* cur = head;
        Node* newCur = newHead;
        vector<Node*> randoms;
        vector<Node*> oriNodes;
        vector<Node*> newNodes;
        int index = 0;
        oriNodes.push_back(head);
        newNodes.push_back(newHead);
        randoms.push_back(head->random);
        while (cur->next != nullptr)
        {
            index++;
            newCur->next = new Node(cur->next->val);
            newCur = newCur->next;
            cur = cur->next;
            oriNodes.push_back(cur);
            newNodes.push_back(newCur);
            randoms.push_back(cur->random);
        }
        for (int i = 0; i <= index; i++)
        {
            Node* temp = randoms[i];
            if (temp == nullptr) continue;
            for (int j = 0; j <= index; j++)
            {
                if (oriNodes[j] == temp)
                {
                    newNodes[i]->random = newNodes[j];                
                    break;
                } 
            }
        }
        return newHead;
    }
};
