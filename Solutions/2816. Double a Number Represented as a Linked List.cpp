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
    ListNode* Solver(ListNode* l1, ListNode* l2){
        stack<int> s1, s2;

        while(l1!=NULL){
            s1.push(l1->val);
            l1 = l1->next;
        }

        while(l2!=NULL){
            s2.push(l2->val);
            l2 = l2->next;
        }

        ListNode *ans = nullptr;
        int carry = 0;
        while(!s1.empty() && !s2.empty()){
            int sum = 0;
            if(!s1.empty()){
                sum += s1.top();
                s1.pop();
            }

            if(!s2.empty()){
                sum += s2.top();
                s2.pop();
            }

            sum += carry;
            carry = sum/10;
            ListNode *Node = new ListNode(sum%10);
            Node->next = ans;
            ans = Node;
        }  

        if (carry > 0) {
            ListNode *Node = new ListNode(carry);
            Node->next = ans;
            ans = Node;
        }

        return ans;
    }
    
    ListNode* doubleIt(ListNode* head) {
        ListNode* head1 = head;
        ListNode* head2 = head;
        
        return Solver(head1, head2);   
    }
};
