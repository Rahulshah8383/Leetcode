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
    /*
    ListNode* reverseList(ListNode* head){
        if(head==NULL || head->next==NULL){
            return head;
        }

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* Nxt = head->next;

        while(Nxt != NULL){
            curr->next = prev;
            prev = curr;
            curr = Nxt;
            Nxt = Nxt->next;
        }
        curr->next = prev;
        return curr;
    }

    ListNode* Helper(ListNode* l1, ListNode* l2){
        ListNode *ans = new ListNode();
        ListNode *temp = ans;
        int carry = 0;

        while(l1 != NULL || l2 != NULL || carry){
            int sum = 0;
            if(l1 != NULL){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL){
                sum += l2->val;
                l2 = l2->next;
            }

            sum += carry;
            carry = sum/10;
            ListNode *Node = new ListNode(sum%10);
            temp->next = Node;
            temp = temp->next;
        }
        
        return reverseList(ans->next);   
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseList(l1);
        l2 = reverseList(l2);

        return Helper(l1, l2);
    }*/

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

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // l1 = reverseList(l1);
        // l2 = reverseList(l2);

        // return Helper(l1, l2);

        return Solver(l1, l2);
    }
};
