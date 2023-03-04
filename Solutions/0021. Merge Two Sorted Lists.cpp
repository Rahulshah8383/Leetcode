class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *temp=new ListNode(-1);
        ListNode *head=temp;

        
        while(list1!=NULL && list2!=NULL){
            if(list1->val <=list2->val){
                head->next = list1;
                list1 = list1->next;
            }
            else{
                head->next = list2;
                list2 = list2->next;
            }
            head = head->next;
        }

        if(list1!=NULL){
            head->next = list1;
        }
        else{
            head->next = list2;
        }
        return temp->next;
    }
};
