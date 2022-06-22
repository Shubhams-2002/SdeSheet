/************************************************************

    Following is the linked list node structure

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
#include<bits/stdc++.h>
class compare {
  public:
    bool operator()(Node<int>* a, Node<int>* b) {
        return (a->data > b->data);
    }
};
Node<int>* mergeKLists(vector<Node<int>*> &listArray)
{
    priority_queue< Node<int>*, vector<Node<int>*>, compare> minHeap;
    for(int i=0; i<listArray.size(); i++) {
        if(listArray[i]!=NULL) { //super imoortant condn
            minHeap.push(listArray[i]);
        }
    }
    
    Node<int>* dummy = new Node<int>(0);
    Node<int>* temp = dummy;
    while(minHeap.size() > 0) {
        Node<int>* t = minHeap.top();
        minHeap.pop();
        if(t->next!=NULL) {
            minHeap.push(t->next);
        }
        temp->next = t;
        temp = temp->next;
    }
    
    return dummy->next;
}
