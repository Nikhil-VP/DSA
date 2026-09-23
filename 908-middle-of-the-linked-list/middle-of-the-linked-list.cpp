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
    ListNode* middleNode(ListNode* head) {

      int n = 0;
      ListNode* temp =head;
      while(temp->next != NULL){
        n += 1;
        temp = temp->next;
      }
      if(n==0)return head;
      n += 1;
    int mid = n/2;
    n =0;
    temp =head;
    while(temp->next != NULL){
        n += 1;
        if(n==mid) break;
        temp = temp->next;
      }
    return temp->next;
    }
};