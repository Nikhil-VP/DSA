class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) return nullptr;

        ListNode* currenta = headA;
        ListNode* currentb = headB;

        while (currenta != currentb) {
            // If currenta reaches the end of List A, switch to headB
            currenta = (currenta == nullptr) ? headB : currenta->next;
            
            // If currentb reaches the end of List B, switch to headA
            currentb = (currentb == nullptr) ? headA : currentb->next;
        }

        // Returns either the intersection node or nullptr
        return currenta; 
    }
};