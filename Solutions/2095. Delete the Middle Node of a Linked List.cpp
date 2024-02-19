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
    // int length(ListNode* head){
    //     ListNode* temp = head;
    //     int len = 0;

    //     while(temp != nullptr){
    //         len++;
    //         temp = temp->next;
    //     }

    //     return len;
    // }

    // ListNode* deleteMiddle(ListNode* head) {
    //     int len = length(head);
    //     if(len == 1){
    //         return nullptr;
    //     }

    //     int mid = len/2;
    //     int count = 1;
    //     ListNode* ptr = head;

    //     while(count != mid){
    //         count++;
    //         ptr = ptr->next;
    //     }

    //     ListNode* temp = ptr->next;
    //     ptr->next = temp->next;
    //     temp = NULL;

    //     return head;
    // }

    ListNode* deleteMiddle(ListNode* head){
        if(head->next == nullptr){
            return nullptr;
        }

        ListNode *slow = head;
        ListNode *fast = head->next->next;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        slow->next = slow->next->next;
        return head;
    }
};
