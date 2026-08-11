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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int l=0;
        ListNode* current = head;
        while (current != nullptr){
            l++;
            current = current->next;
        }
        if(l == 1 && n == 1)
        return nullptr;
        if(n==l){
            ListNode* newhead = head->next;
            delete head;
            return newhead;
        }
        ListNode* current1 = head;
        for(int i=0;i < l-n-1;i++){
           current1 = current1->next; 
        }

        current1->next = current1->next->next;
        return head;
    }
};