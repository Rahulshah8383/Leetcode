/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // if(head == NULL || head->next == NULL){
        //     return false;
        // }

        // ListNode *slow = head;
        // ListNode *fast = head;

        // while(slow != NULL && fast != NULL){
        //     fast = fast->next;
        //     if(fast != NULL){
        //         fast = fast->next;
        //     }

        //     slow = slow->next;

        //     if(slow == fast){
        //         return true;
        //     }
        // }
        // return false;

        if(head==NULL)
            return false;
            
        unordered_map<ListNode*,int> map;
        while(head!=NULL){
            if(map.count(head)>0)
                return true;
            else
                map[head]=1;
            head=head->next;
        }
        return false;
    }
};
