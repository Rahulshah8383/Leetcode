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
        if(head == NULL){
            return head;
        }
        int len = 1;
        ListNode *last = head;
        while(last->next){
            last = last->next;
            len++;
        }

        last->next = head;
        k = k%len;

        for(int i=0;i<len-k;i++){ last = last->next; }
        ListNode *newhead = last->next;
        last->next = NULL;
        return newhead;
    }
};
