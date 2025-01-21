// level - medium
// https://leetcode.com/problems/copy-list-with-random-pointer/description/

// tc : O(2*n)
// sc : O(n) -> map + O(n) -> copy elements

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return head;

        unordered_map<Node*, Node*> mp;

        Node* temp = head;
        while(temp != NULL) {
            Node* newNode = new Node(temp->val);
            mp[temp] = newNode;

            temp = temp->next;
        }

        temp = head;

        while(temp != NULL) {
            Node* copyNode = mp[temp];

            copyNode->next = mp[temp->next];
            copyNode->random = mp[temp->random];

            temp = temp->next;
        }

        return mp[head];
    }
};

// tc : O(3*n)
// sc : O(n) -> copy elements

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return head;

        Node* temp = head;
        while(temp != NULL) {
            Node* newNode = new Node(temp->val);

            newNode->next = temp->next;
            temp->next = newNode;

            temp = newNode->next;
        }

        temp = head;
        while(temp != NULL) {
            if(temp->random != NULL) 
                temp->next->random = temp->random->next;

            temp = temp->next->next;
        }

        Node* ans = head->next;
        Node* copy = ans;
        temp = head;
        while(temp != NULL) {
            temp->next = temp->next->next;

            if(copy->next != NULL) copy->next = copy->next->next;

            copy = copy->next;
            temp = temp->next;
        }

        return ans;
    }
};

