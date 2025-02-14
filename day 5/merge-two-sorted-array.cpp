// level - easy
// https://leetcode.com/problems/merge-two-sorted-lists/description/

// tc : O(len(l1)+len(l2))
// sc : O(1)

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
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;

        ListNode* prev;
        ListNode* head;

        if(list1->val <= list2->val) {
            head = list1;
            prev = list1;
            list1 = list1->next;
        }
        else {
            head = list2;
            prev = list2;
            list2 = list2->next;
        }

        while(list1 != NULL && list2 != NULL) {
            if(list1->val <= list2->val) {
                prev->next = list1;
                prev = prev->next;
                list1 = list1->next;
            }
            else {
                prev->next = list2;
                prev = prev->next;
                list2 = list2->next;
            }
        }

        if(list1 != NULL) {
            prev->next = list1;
        }

        if(list2 != NULL) {
            prev->next = list2;
        }

        return head;
    }
};