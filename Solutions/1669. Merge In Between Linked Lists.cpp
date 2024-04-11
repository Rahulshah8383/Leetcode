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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* ans = dummy;
        int len = 0;

        while(list1 != nullptr){
            dummy->next = list1;
            list1 = list1->next;
            dummy = dummy->next;
            len++;

            if(len == a){
                break;
            }
        }

        while(len <= b && list1 != nullptr){
            list1 = list1->next;
            len++;
        }

        while(list2 != nullptr){
            dummy->next = list2;
            list2 = list2->next;
            dummy = dummy->next;
            len++;
        }

        while(list1 != nullptr){
           dummy->next = list1;
            list1 = list1->next;
            dummy = dummy->next;
            len++;
        }

        return ans->next;
    }
};
