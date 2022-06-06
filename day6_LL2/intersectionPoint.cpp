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
int length(Node *head) {
    Node* temp = head;
    int len=0;
    while(temp) {
        temp = temp->next;
        len++;
    }
    return len;
}

int findIntersection(Node *firstHead, Node *secondHead)
{
    int l1 = length(firstHead);
    int l2 = length(secondHead);
    
    Node* t1 = firstHead;
    Node* t2 = secondHead;
    
    int diff = l1-l2;
    while(diff!=0) {
        if(diff>0) {
            t1=t1->next;
            diff--;
        }
        else {
            t2=t2->next;
            diff++;
        }
    }
    
    while(t1!=t2) {
        t1=t1->next;
        t2=t2->next;
    }
    
    return (t1) ? t1->data : -1;
}