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
    int len;
    while(temp) {
        temp = temp->next;
        len++;
    }
    return len;
}

Node *findMiddle1(Node *head) {
    if(head==NULL) {
        return head;
    }
    
    Node* temp = head;
    int len;
    while(temp) {
        temp = temp->next;
        len++;
    }
    
    int mid = len / 2;
    //cout<<length(head)<<" "<<endl;
    temp = head;
    while(mid) {
        temp = temp->next;
        mid--;
    }
    
    return temp;
}

Node *findMiddle(Node *head) {
    Node* fast = head;
    Node* slow = head;
    
    while(fast!=NULL && fast->next!=NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    
    return slow;
}