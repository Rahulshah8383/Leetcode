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
    ListNode* removeElements(ListNode* head, int val) {

        if(head == NULL){
            return 0;
        }

        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *curr = head;
        ListNode *prev = dummy;
        
        while(curr!=NULL){
            if(curr->val == val){
                ListNode *temp = curr;
                prev->next = curr->next;
                curr = curr->next;
                delete temp;
            }
            else{
                prev = curr;
                curr = curr->next;
            } 
        }
        return dummy->next;
    }
};
