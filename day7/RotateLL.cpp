/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp = head;
        if(head==NULL || head->next==NULL) {
            return head;
        }
        int len=0;
        while(temp) {
            temp = temp->next;
            len++;
        }
        temp = head;
        k=k%len;
        for(int i=0; i<len-k-1; i++) {
            temp = temp->next;
        }
        ListNode* new_tail = temp;
        ListNode* new_head = temp->next;
        while(temp->next) {
            temp = temp->next;
        }
        temp->next = head;
        new_tail->next = NULL;
        return (new_head) ? new_head : head;
    }
};