// level - easy
// https://leetcode.com/problems/middle-of-the-linked-list/description/

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
    ListNode* middleNode(ListNode* head) {
        int len = 0;

        ListNode* temp = head;

        while(temp != NULL) {
            len++;
            temp = temp->next;
        }

        len = (len/2);

        temp = head;

        while(temp != NULL && len--) {
            temp = temp->next;
        }

        return temp;
    }
};


// tc : O(n)
// sc : O(1)

// fast and slow pointer

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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow=head,*fast=head;
        if(head==NULL || head->next==NULL)
        return head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};