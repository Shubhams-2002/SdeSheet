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

Node *addTwoNumbers(Node *head1, Node *head2)
{
    Node* t1 = head1;
    Node* t2 = head2;
    Node* last = new Node(0);
    int a;
    int carry =0;
    while(t1 && t2) {
        a = t1->data;
        t1->data = (a + t2->data + carry) % 10;
        carry = (a + t2->data + carry) / 10;
        last->next=t1;
        last=last->next;
        t1=t1->next;
        t2=t2->next;
    }
    while(t1) {
        a = t1->data;
        t1->data = (a + carry) % 10;
        carry = (a + carry) / 10;
        last->next=t1;
        last=last->next;
        t1=t1->next;
    }
    while(t2) {
        a = t2->data;
        t2->data = (a + carry) % 10;
        carry = (a + carry) / 10;
        last->next=t2;
        last=last->next;
        t2=t2->next;
    }
    if(carry) {
        Node* c = new Node(carry);
        last->next = c;
    }
    
    return head1;
}