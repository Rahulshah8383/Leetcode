class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nxt = NULL;
        
        while(curr != NULL){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        
        return prev;
    }

    ListNode* removeNodes(ListNode* head) {
        ListNode *temp = reverse(head);
        
        ListNode *new_head = NULL;
        ListNode *Trail = NULL;
        
        // while(temp != NULL){
        //     cout<<temp->data<<" ";
        //     temp = temp->next;
        // }
        
        int k = -1;
        
        while(temp != NULL){
            if(temp->val >= k){
                ListNode* newNode = new ListNode(temp->val);
                if(new_head == NULL){
                    new_head = newNode;
                    Trail = newNode;
                }
                else{
                    Trail->next = newNode;
                    Trail = Trail->next;
                }
                k = temp->val;
            }
            temp = temp->next;
        }
        
        return reverse(new_head);
    }
};
