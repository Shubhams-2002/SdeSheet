
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


class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp =head;
        Node* dummy = new Node(0);
        Node* ctemp = dummy;
        unordered_map<Node*, Node*> hash;
        
        while(temp) {
            Node* n = new Node(temp->val);
            ctemp->next = n;
            ctemp = ctemp->next;
            hash[temp] = ctemp;
            temp = temp->next;
        }
        temp =head;
        ctemp = dummy->next;
        while(temp) {
            ctemp->random = hash[temp->random];
            ctemp = ctemp->next;
            temp = temp->next;
        }
        
        return dummy->next;
    }
};