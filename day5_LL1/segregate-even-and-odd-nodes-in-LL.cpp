#include<bits/stdc++.h>
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

Node* segregateEvenOdd(Node* head)
{
    if(head==NULL) return NULL;
    Node* dummy = new Node(0);
    dummy->next = head;
    
    Node* even = dummy;
    while(even!=NULL && even->next!=NULL && even->next->data%2 ==0) {
        even = even->next;
    }
    Node* odd = even->next;
    Node* firstOdd = odd;
    
    while(odd!=NULL && odd->next!=NULL && even!=NULL && even->next!=NULL) {
        while(odd!=NULL && odd->next!=NULL && odd->next->data%2 ==1) {
            odd = odd->next;
        }
        even->next = odd->next;
        if(even->next) even = even->next;
        
        while(even!=NULL && even->next!=NULL && even->next->data%2 ==0) {
            even = even->next;
        }
        odd->next = even->next;
        odd = odd->next;
    }
    
    even->next = firstOdd;
    return dummy->next;
}

