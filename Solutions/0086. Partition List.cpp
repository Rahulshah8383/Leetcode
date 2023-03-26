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
    ListNode* partition(ListNode* head, int x) {
        //queue
        queue<int> q1;
        queue<int> q2;


        while(head!=NULL){
            q1.push(head->val);
            head = head->next;
        }
        ListNode *temp = head;

        while(!q1.empty()){
            int data = q1.front();
            if(data < x){
                ListNode *newNode = new ListNode(data);
                if(head==NULL){
                    head = newNode;
                    temp = newNode;
                }
                else{
                    temp->next = newNode;
                    temp = temp->next;
                }
            }
            else{
                q2.push(data);
            }
            q1.pop();
        }

        while(!q2.empty()){
            ListNode *newNode = new ListNode(q2.front());
            if(head==NULL){
                    head = newNode;
                    temp = newNode;
            }
            else{
                temp->next = newNode;
                temp = temp->next;
            }
            q2.pop();
        }
        return head;
    }
};
