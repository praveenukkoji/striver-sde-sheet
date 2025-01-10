// level - medium
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

// tc : O(len(l1)+len(l2))
// sc : O(max(len(l1), len(l2)) + 1)

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* temp = head;

        int carry = 0;
        int sum = 0;

        while(l1 != NULL && l2 != NULL) {
            sum = l1->val + l2->val + carry;

            if(sum < 10) {
                temp->next = new ListNode(sum);
                carry = 0;
            }
            else {
                temp->next = new ListNode(sum%10);
                carry = 1;
            }

            temp = temp->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1 != NULL) {
            sum = l1->val + carry;

            if(sum < 10) {
                temp->next = new ListNode(sum);
                carry = 0;
            }
            else {
                temp->next = new ListNode(sum%10);
                carry = 1;
            }

            temp = temp->next;
            l1 = l1->next;
        }

        while(l2 != NULL) {
            sum = l2->val + carry;

            if(sum < 10) {
                temp->next = new ListNode(sum);
                carry = 0;
            }
            else {
                temp->next = new ListNode(sum%10);
                carry = 1;
            }

            temp = temp->next;
            l2 = l2->next;
        }

        if(carry) {
            temp->next = new ListNode(carry);
        }

        return head->next;
    }
};

// tc : O(max(len(l1), len(l2)))
// sc : O(max(len(l1), len(l2)) + 1)

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* temp = head;

        int carry = 0;
        int sum = 0;

        while(l1 != NULL || l2 != NULL || carry) {
            sum = 0;
            if(l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }

            if(l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }

            sum += carry;
            carry = sum/10;
            temp->next = new ListNode(sum%10);
            temp = temp->next;
        }

        return head->next;
    }
};