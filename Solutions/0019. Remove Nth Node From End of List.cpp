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
        ListNode *temp=head;
        long len = 0;
        while(temp!= NULL){
            len++;
            temp = temp->next;
        }

        if(n>len){
            return head;
        }

        if(len == n){
            return head->next;
        }

        else{
            int diff = len - n;         
            ListNode* prev= NULL;      
            ListNode* curr = head;        
            for(int i = 0;i < diff;i++){
                prev = curr;           
                curr = curr->next;     
            }
            prev->next = curr->next;
            return head;
        }
        return head;
    }
};
