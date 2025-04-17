// level - medium
// https://leetcode.com/problems/lru-cache/description/

// tc : O(1) -> for all function
// sc : O(capacity) -> LL + O(capactiy) -> map

class LRUCache {
public:
    class Node {
    public:
        int key;
        int value;
        Node* next;
        Node* prev;

        Node(int key, int value) {
            this->key = key;
            this->value = value;

            next = nullptr;
            prev = nullptr;
        }
    };

    Node* tail;
    Node* head;

    unordered_map<int, Node*> mp;
    int size;

    LRUCache(int capacity) {
        size = capacity;

        tail = new Node(-1, -1);
        head = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    void removeNode(Node* temp) {
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
    }

    void insertNode(Node* temp) {
        temp->next = head->next;
        head->next->prev = temp;
        head->next = temp;
        temp->prev = head;
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        Node* temp = mp[key];

        removeNode(temp);
        insertNode(temp);

        return temp->value;
    }

    void put(int key, int value) {
        Node* temp;
        if (mp.find(key) != mp.end()) {
            temp = mp[key];
            temp->value = value;

            removeNode(temp);
            insertNode(temp);
            mp[key] = temp;

            return;
        } 
        
        if (mp.size() == size) {
            mp.erase(tail->prev->key);

            tail->prev = tail->prev->prev;
            tail->prev->next = tail;

            temp = new Node(key, value);
            insertNode(temp);
            mp[key] = temp;

            return;
        } 
        
        temp = new Node(key, value);
        insertNode(temp);
        mp[key] = temp;

        return;
    }
};