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
    int length(ListNode* head){
        ListNode* temp = head;
        int len = 0;
        while(temp != NULL){
            len++;
            temp = temp->next;
        }
        return len;
    }

    ListNode* middleNode(ListNode* head) {
        if(head == NULL){
            return NULL;
        }

        int len = length(head);
        
        int mid = len/2;

        while(mid--){
            head = head->next;
        }
        
        return head;
    }
};
