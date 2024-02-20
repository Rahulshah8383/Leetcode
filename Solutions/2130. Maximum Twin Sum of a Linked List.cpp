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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;

        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* nxt = head->next;

        while(curr){
            curr->next = prev;
            prev = curr;
            curr = nxt;
            if(nxt)
                nxt = nxt->next;
        }
        return prev;
    }

    int pairSum(ListNode* head) {
        if(head == NULL){
            return NULL;
        }

        if(head->next->next == NULL){
            return head->val + head->next->val;
        }

        ListNode* temp = head, *slow = head, *fast = head->next->next;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* rev_head = reverseList(slow->next);
        slow->next = rev_head;
        
        int ans = 0;
        while(rev_head){
            int data = head->val + rev_head->val;
            ans = max(ans, data);
            head = head->next;
            rev_head = rev_head->next;
        }
        
        return ans;

    }
};
