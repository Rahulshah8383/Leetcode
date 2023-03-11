/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *x = headA, *y = headB;

        while(1){
            if(x == y){
                return x;
            }

            if(x == NULL){
                x = headB;
            }
            else{
                x = x->next;
            }

            if(y == NULL){
                y = headA;
            }
            else{
                y = y->next;
            }
        }

        return NULL;
    }
};
