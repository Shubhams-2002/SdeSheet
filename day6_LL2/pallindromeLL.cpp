#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

bool isPalindrome(LinkedListNode<int> *head) {
    if(head==NULL) return true;
    LinkedListNode<int>* temp = head;
    LinkedListNode<int>* prev = NULL;
    LinkedListNode<int>* curr = new LinkedListNode<int>(temp->data);
    LinkedListNode<int>* nxt;

    while(curr) {
        curr->next = prev;
        
        prev = curr;
        temp = temp->next;
        curr = (temp)? new LinkedListNode<int>(temp->data) : NULL;
    }
    LinkedListNode<int>* temp2 = prev; //as prev is the head of new reversed LL
    temp = head;
    while(temp && temp2 && temp->data==temp2->data) {
        temp = temp->next;
        temp2=temp2->next;
        
    }
    if(temp!=NULL) {
        return false;
    }
    else {
        return true;
    }
}