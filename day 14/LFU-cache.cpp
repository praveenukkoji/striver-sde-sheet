// level - hard
// https://leetcode.com/problems/lfu-cache/description/

// tc : O(1) for all functions
// sc : O(capacity)

class Node {
public:
    int key;
    int value;
    int freq;
    Node* next;
    Node* prev;

    Node(int key, int value) {
        this->key = key;
        this->value = value;
        freq = 1;
        next = nullptr;
        prev = nullptr;
    }
};

class List {
public:
    int size;
    Node* tail = new Node(-1, -1);
    Node* head = new Node(-1, -1);

    List() {
        tail->prev = head;
        head->next = tail;
        size = 0;
    }

    void addNode(Node* temp) {
        temp->next = head->next;
        head->next->prev = temp;
        head->next = temp;
        temp->prev = head;

        size++;
    }

    void removeNode(Node* temp) {
        Node* prevNode = temp->prev;
        Node* nextNode = temp->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;

        size--;
    }
};

class LFUCache {
public:
    int size;
    int minFreq;

    unordered_map<int, Node*> keyToNode;
    unordered_map<int, List*> freqToList;

    LFUCache(int capacity) {
        size = capacity;
        minFreq = 0;
    }

    void updateFreq(Node* temp) {
        keyToNode.erase(temp->key);
        freqToList[temp->freq]->removeNode(temp);

        if(temp->freq == minFreq && freqToList[temp->freq]->size == 0) {
            minFreq++;
        }

        List* newList;
        if(freqToList.find(temp->freq + 1) != freqToList.end()) {
            newList = freqToList[temp->freq + 1];
        }
        else {
            newList = new List();
        }

        temp->freq += 1;
        newList->addNode(temp);
        freqToList[temp->freq] = newList;
        keyToNode[temp->key] = temp;
    }
    
    int get(int key) {
        if(keyToNode.find(key) == keyToNode.end()) return -1;

        Node* temp = keyToNode[key];
        updateFreq(temp);
        return temp->value;
    }
    
    void put(int key, int value) {
        Node* temp;
        if(keyToNode.find(key) != keyToNode.end()) {
            temp = keyToNode[key];
            temp->value = value;
            updateFreq(temp);
        }
        else {
            temp = new Node(key, value);

            if(keyToNode.size() == size) {
                List* list = freqToList[minFreq];
                keyToNode.erase(list->tail->prev->key);
                list->removeNode(list->tail->prev);
            }

            minFreq = 1;

            List* list = new List();
            if(freqToList.find(minFreq) != freqToList.end()) {
                list = freqToList[minFreq];
            }

            list->addNode(temp);
            keyToNode[key] = temp;
            freqToList[minFreq] = list;
        }
    }
};