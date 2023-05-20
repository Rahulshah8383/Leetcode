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
    // Approach 1: using vector
    void reorderList(ListNode* head) {
        vector<ListNode*> v;

        ListNode* temp = head;

        while(temp !=NULL){
            v.push_back(temp);
            temp  = temp ->next;
            v.back()->next = NULL;
        }

        ListNode* newHead = new ListNode(-1); // Dummy Node
        ListNode *curr = newHead; 

        while(!v.empty()){
            curr->next = v.front();
            v.erase(v.begin());
            curr = curr->next;

            if(!v.empty()){
                curr->next = v.back();
                v.pop_back();
                curr = curr->next;
            }
        }
        head = newHead->next;
    }
    */

    /* 
    // Approach 1: using deque
    void reorderList(ListNode* head) {
        deque<ListNode*> dq;
        ListNode* temp = head;

        while(temp !=NULL){
            dq.push_back(temp);
            temp  = temp ->next;
            dq.back()->next = NULL;
        }
        // deque -> 1 2 3 4 5

        ListNode* newHead = new ListNode(-1); // Dummy Node
        ListNode *curr = newHead;

        while(!dq.empty()){
            curr->next = dq.front();
            dq.pop_front();
            curr = curr->next;

            if(!dq.empty()){
                curr->next = dq.back();
                dq.pop_back();
                curr = curr->next;
            }
        }
        head = newHead->next;
    }
    */

    // Approach 3: using stack
    void reorderList(ListNode* head) {
        stack<ListNode*> s1, s2, tempStack;

        ListNode* temp = head;
        while(temp!=NULL){
            tempStack.push(temp);
            s1.push(temp);
            temp = temp->next;
            s1.top()->next = NULL;
        }

        while(!tempStack.empty()){
            s2.push(tempStack.top());
            tempStack.pop();
            s2.top()->next = NULL;
        }

        int count = s1.size();
        ListNode* newHead = new ListNode(-1);
        ListNode* curr = newHead;

        while(count){
            curr->next = s2.top();
            s2.pop();
            curr = curr->next;
            count--;

            if(count){
                curr->next = s1.top();
                s1.pop();
                curr = curr->next;
                count--;
            }
        }
        head = newHead->next;
    }
};
