class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode *new_head = NULL;
        ListNode *Trail = NULL;    
        ListNode *temp = head;

        while(temp != NULL){
           ListNode *newNode = new ListNode(temp->val);
            if(new_head == NULL){
                new_head = newNode;
                Trail = newNode;
            }
            else{
                Trail->next = newNode;
                Trail = Trail->next;
            }
            temp = temp->next;
            if(temp != NULL){
                temp  = temp->next;
            }
        }

        temp = head->next;
        while(temp != NULL){
            ListNode *newNode = new ListNode(temp->val);
            if(new_head == NULL){
                new_head = newNode;
                Trail = newNode;
            }
            else{
                Trail->next = newNode;
                Trail = Trail->next;
            }
            temp = temp->next;
            if(temp != NULL){
                temp  = temp->next;
            }
        }
    
        return new_head;
    }
};
