#include <bits/stdc++.h> 
/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    Node<int>* new_head;
    Node<int>* to_delete;
    Node<int>* temp;
    if(first && second) {
        if(first->data <= second->data) {
            new_head = first;
            first = first->next;
        }
        else {
            new_head = second;
            second= second->next;
        }
        temp = new_head;
    }
    else if(first==NULL && second) {
        return second;
    }
    else if(first && second==NULL) {
        return first;
    }
    else {
        return NULL;
    }
    while(first && second) {
        if(first->data <= second->data) {
            temp->next = first;
            temp = temp->next;
            first = first->next;
        }
        else {
            temp->next = second;
            temp = temp->next;
            second = second->next;
        }
    }
    while(first) {
        temp->next = first;
            temp = temp->next;
            first = first->next;
    }
    while(second) {
        temp->next = second;
            temp = temp->next;
            second = second->next;
    }
    
    return new_head;
}
