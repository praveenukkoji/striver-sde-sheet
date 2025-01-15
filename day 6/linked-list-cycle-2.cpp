// level - medium
// https://leetcode.com/problems/linked-list-cycle-ii/description/

// tc : O(len(n))
// sc : O(1)

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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return NULL;

        ListNode* slow = head;
        ListNode* fast = head;

        bool isCyclic = false;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) {
                isCyclic = true;
                break;
            }
        }

        if(!isCyclic) {
            return NULL;
        }

        fast = head;
        while(fast != NULL) {
            if(slow == fast) return slow;

            slow = slow->next;
            fast = fast->next;
        }

        return NULL;
    }
};