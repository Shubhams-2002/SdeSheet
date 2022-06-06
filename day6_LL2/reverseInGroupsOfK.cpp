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

Node *getListAfterReverseOperation(Node *head, int n, int b[]){
    Node* temp=head;
    Node* pTemp= new Node(0);
    
    for(int i=0; temp && i<n; i++) {
        Node* prev=NULL;
        Node* curr=temp;
        Node* nxt;
        for(int j=0; curr && j<b[i]; j++) {
            nxt = curr->next;
            
            curr->next = prev;
            
            prev = curr;
            curr = nxt;
        }
        if(!prev) continue;
        if(i==0) {
            head = prev;
            //pTemp = temp;
        }
        else {
            pTemp->next=prev;
            //pTemp = temp;
        }
        pTemp = temp;
        temp = curr;
    }
    pTemp->next = temp;
    return head;
}