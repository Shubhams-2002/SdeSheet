#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

Node *firstNode(Node *head)
{
    Node* slow = head;
    Node* fast = head;
    
    if(head==NULL) {
        return NULL;
    }
    if(head->next == NULL) {
        return NULL;
    }
    
    do {
        slow = slow->next;
        fast = fast->next->next;
    } while (fast && fast->next && slow!=fast);
    
    if(slow==fast) {
        fast = head;
        while(slow!=fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
    else {
        return NULL;
    }
}