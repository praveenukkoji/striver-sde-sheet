// level - easy
// https://leetcode.com/problems/intersection-of-two-linked-lists/description/

// tc : O(len(ll1) + len(ll2))
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // if(headA == headB) return headA;

        int lenA = 0;
        int lenB = 0;

        ListNode* tempA = headA;
        ListNode* tempB = headB;

        while(tempA != NULL) {
            lenA++;
            tempA = tempA->next;
        }

        while(tempB != NULL) {
            lenB++;
            tempB = tempB->next;
        }

        tempA = headA;
        tempB = headB;

        int diff = 0;

        if(lenA > lenB) {
            diff = lenA-lenB;

            while(diff--) {
                tempA = tempA->next;
            }
        }
        else if(lenA < lenB) {
            diff = lenB-lenA;

            while(diff--) {
                tempB = tempB->next;
            }
        }

        while(tempA != NULL && tempB != NULL) {
            if(tempA == tempB) {
                return tempA;
            }

            tempA = tempA->next;
            tempB = tempB->next;
        }

        return NULL;
    }
};