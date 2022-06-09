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
LinkedListNode<int> *reverse(LinkedListNode<int> *head) 
{
    LinkedListNode<int>* prev = NULL;
    LinkedListNode<int>* curr = head;
    LinkedListNode<int>* nxt;
    
    while(curr) {
        nxt = curr->next;
        
        curr->next = prev;
        
        prev = curr;
        curr = nxt;
    }
    
    return prev;
}
bool isPalindrome(LinkedListNode<int> *head) {
    if(head==NULL || head->next==NULL) {
        return true;
    }
    LinkedListNode<int>* slow = head;
    LinkedListNode<int>* fast = head;
    
    while(fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    slow->next = reverse(slow->next);
    slow = slow->next;
    LinkedListNode<int>* temp = head;
    while(slow) {
        if(slow->data != temp->data) {
            return false;
        }
        slow = slow->next;
        temp = temp->next;
    }
    return true;
}
bool isPalindrome1(LinkedListNode<int> *head) {
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