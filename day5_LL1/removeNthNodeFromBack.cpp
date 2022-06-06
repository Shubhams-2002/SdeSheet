// Optimal code
ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * start = new ListNode();
        start -> next = head;
        ListNode* fast = start;
        ListNode* slow = start;     

        for(int i = 1; i <= n; ++i)
            fast = fast->next;
    
        while(fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        
        slow->next = slow->next->next;
        
        return start->next;
    }
    
//MyCode which has to cover several edge cases    
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

LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int K)
{
    if(head==NULL || K==0) return head;
    
    LinkedListNode<int>* back=head;
    LinkedListNode<int>* front=head;
    LinkedListNode<int>* to_delete;
    while(K && front) {
        front = front->next;
        K--;
    }
    if(front==NULL) {
        to_delete = head;
        head=head->next;
        delete to_delete;
        return head;
    }
    while(front->next) {
        back=back->next;
        front=front->next;
    }
    to_delete = back->next;
    back->next = back->next->next;
    delete to_delete;
    
    return head;
}