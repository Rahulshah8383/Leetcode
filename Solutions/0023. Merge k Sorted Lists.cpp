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
#include<stack>

class Solution {
public:
    void sortStack(std::stack<int>& stack) { 
        std::stack<int> tempStack;

        while (!stack.empty()) {
            int temp = stack.top();
            stack.pop();

            while (!tempStack.empty() && tempStack.top() > temp) {
                stack.push(tempStack.top());
                tempStack.pop();
        }

        tempStack.push(temp);
        }

        while (!tempStack.empty()) {
            stack.push(tempStack.top());
            tempStack.pop();
        }
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        stack<int> st;
        for(int i=0;i<lists.size();i++){
            ListNode *temp = lists[i];

            while(temp!=NULL){
                st.push(temp->val);
                temp = temp->next;
            }
        }

        sortStack(st); // O(N^2)

        ListNode *head = NULL;
        ListNode *curr = NULL;
        while(!st.empty()){
            if(head == NULL){
                head = new ListNode(st.top());;
                curr = head;
            }
            else{
                curr->next =new ListNode(st.top());
                curr = curr->next;
            }
            st.pop();
        }
        return head;
    }
};
