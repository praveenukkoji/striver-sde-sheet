// level - medium
// https://leetcode.com/problems/rotate-list/description/

// tc : O(ll) + O(k*ll) if k == n O(ll^2)
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;

        int len = 0;
        ListNode* temp = head;
        while(temp != NULL) {
            len++;
            temp = temp->next;
        }

        k = k % len;
        if(k == 0) return head;
        
        while(k--) {
            temp = head;

            ListNode* lastNode = temp;

            while(temp->next != NULL) {
                lastNode = temp;
                temp = temp->next;
            }

            lastNode->next = NULL;
            temp->next = head;
            head = temp;
        }

        return head;
    }
};

// tc : O(ll) + O(ll - (ll%k)) => Reason: O(ll) for calculating the length-of-the-list. O(ll - (ll%k)) for breaking link.
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;

        int len = 0;
        ListNode* temp = head;
        while(temp != NULL) {
            len++;
            temp = temp->next;
        }

        k = k % len;
        if(k == 0) return head;

        ListNode* lastNode = head;

        while(lastNode->next != NULL) {
            lastNode = lastNode->next;
        }
        lastNode->next = head;

        temp = head;
        ListNode* prev = NULL;

        int itr = len - k;
        while(itr--) {
            prev = temp;
            temp = temp->next;
        }

        prev->next = NULL;
        head = temp;

        return head;
    }
};