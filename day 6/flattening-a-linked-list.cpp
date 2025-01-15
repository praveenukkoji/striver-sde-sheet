// level - hard
// https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1

// tc : O(O(N*M) + O(N*M log(N*M)) + O(N*M))
// sc : O(N*M) + O(N*M) as new node are added at bottom

/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

class Solution {
  public:
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *root) {
        // Your code here
        vector<int> arr;
        
        Node* temp = root;
        while(temp != NULL) {
            Node* btm = temp;
            
            while(btm != NULL) {
                arr.push_back(btm->data);
                btm = btm->bottom;
            }
            
            temp = temp->next;
        }
        
        sort(arr.begin(), arr.end());
        
        temp = root;
        for(auto &it : arr) {
            temp->bottom = new Node(it);
            temp = temp->bottom;
        }
        
        return root->bottom;
    }
};

// tc : O(N*(2*M))
// sc : O(1)

class Solution {
  public:
    Node* merge(Node* list1, Node* list2) {
        Node* ans = new Node(-1);
        Node* temp = ans;
        
        while(list1 != NULL && list2 != NULL) {
            if(list1->data <= list2->data) {
                temp->bottom = list1;
                temp = temp->bottom;
                list1 = list1->bottom;
            }
            else {
                temp->bottom = list2;
                temp = temp->bottom;
                list2 = list2->bottom;
            }
        }
        
        if(list1) {
            temp->bottom = list1;
        }
        if(list2) {
            temp->bottom = list2;
        }
        
        // step not needed already next for every node is NULL by default
        // if(ans->bottom) ans->bottom->next = NULL;
        
        return ans->bottom;
    }
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *head) {
        // Your code here
        
        if(head == NULL || head->next == NULL) return head;
        
        Node* newHead = flatten(head->next);
        newHead = merge(newHead, head);
        
        return newHead;
    }
};