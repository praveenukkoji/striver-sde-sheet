// level - medium
// https://leetcode.com/problems/delete-node-in-a-linked-list/description/

// tc : O( len(linked_list) - pos(node))
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
    void deleteNode(ListNode* node) {
        ListNode* prev = node;
        node = node->next;

        while(node != NULL) {
            prev->val = node->val;

            if(node->next == NULL) {
                prev->next = NULL;
                break;
            }

            prev = prev->next;
            node = node->next;
        }
    }
};

// tc : O(1)
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
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};