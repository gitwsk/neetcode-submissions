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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode *head = nullptr, *temp = nullptr;
        if (!list1 && !list2) {
            return head;
        } else if (!list1 && list2) {
            return list2;
        } else if (list1 && !list2) {
            return list1;
        }

        if (list1->val <= list2->val) {
            temp = head = list1;
            list1 = list1->next;
        } else {
            temp = head = list2;
            list2 = list2->next;
        }
        while (temp) {
            if (list1 && list2) {
                if (list1->val <= list2->val) {
                    temp->next = list1;
                    list1 = list1->next;
                } else {
                    temp->next = list2;
                    list2 = list2->next;
                }
            } else if (!list1) {
                temp->next = list2;
                break;
            } else if (!list2) {
                temp->next = list1;
                break;
            }
            temp = temp->next;
        }

        
        return head;
    }
};
