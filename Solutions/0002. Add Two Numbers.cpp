class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       ListNode *temp1=new ListNode();
            ListNode *temp2=temp1;
            int carry=0;
            while(l1!=NULL || l2!=NULL || carry){
                int sum=0;
                if(l1!=NULL){
                    sum+=l1->val;
                    l1=l1->next;
                }
                 if(l2!=NULL){
                    sum+=l2->val;
                    l2=l2->next;
                }
                sum+=carry;
                carry=sum/10;
                ListNode *Node=new ListNode(sum%10);
                temp2->next=Node;
                temp2=temp2->next;
            } 
            return temp1->next;   
    }
};
