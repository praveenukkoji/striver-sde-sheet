// level - hard
// https://leetcode.com/problems/reverse-nodes-in-k-group/description/

// tc : O(k=>finding_kthNode + k=>reversing_ll)
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
    ListNode* findKthNode(ListNode* temp, int k) {
        --k;
        while(temp != NULL && k--) {
            temp = temp->next;
        }

        return temp;
    }

    void reverseNode(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* temp = head;

        while(temp != NULL) {
            ListNode* front = temp->next;
            temp->next = prev;

            prev = temp;
            temp = front;
        }
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL) return head;

        ListNode* temp = head;
        ListNode* prev = NULL;

        while(temp != NULL) {
            ListNode* kthNode = findKthNode(temp, k);

            if(kthNode == NULL) {
                return head;
            }

            ListNode* nextNode = kthNode->next;
            kthNode->next = NULL;

            reverseNode(temp);

            if(prev != NULL) {
                prev->next = kthNode;
            }

            if(temp == head) { 
                head = kthNode;
            }

            temp->next = nextNode;
            prev = temp;
            temp = nextNode;
        }

        return head;
    }
};