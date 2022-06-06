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

LinkedListNode<int> *reverseLinkedList1(LinkedListNode<int> *head) 
{
    LinkedListNode<int>* prev = NULL;
    LinkedListNode<int>* curr = head;
    LinkedListNode<int>* old_head = head;
    LinkedListNode<int>* nxt;
    
    while(curr) {
        nxt = curr->next;
        
        curr->next = prev;
        
        prev = curr;
        curr = nxt;
    }
    
    return prev;
}

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) {
    if(head==NULL || head->next == NULL) {
        return head;
    }
    
    LinkedListNode<int>* new_head = reverseLinkedList(head->next);
    head->next->next = head;
    head->next = NULL;
    
    return new_head;
}