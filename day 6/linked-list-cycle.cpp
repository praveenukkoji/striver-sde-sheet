// level - easy
// https://leetcode.com/problems/linked-list-cycle/description/

// tc : O(len(ll^2))
// sc : O(len(ll))
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
    bool hasCycle(ListNode *head) {
        if(head == NULL) return false;
        
        unordered_set<ListNode*> st;

        ListNode* temp = head;
        st.insert(temp);
        temp = temp->next;

        while(temp != NULL) {
            if(st.find(temp) != st.end()) {
                return true;
            }

            st.insert(temp);
            temp = temp->next;
        }

        return false;
    }
};

// tc : O(len(ll))
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
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) return true;
        }

        return false;
    }
};