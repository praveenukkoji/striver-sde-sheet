// level - medium
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

// tc : O(len(linked_list))
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL || head->next == NULL) return NULL;

        int len = 0;
        ListNode* temp = head;

        while(temp != NULL) {
            len++;
            temp = temp->next;
        }

        if(len == n) {
            ListNode* newHead = head->next;
            return newHead;
        }

        int pos = len - n - 1;
        temp = head;

        while(temp != NULL && pos--) {
            temp = temp->next;
        }

        temp->next = temp->next->next;

        return head;
    }
};